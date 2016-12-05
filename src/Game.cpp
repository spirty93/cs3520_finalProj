#include <string>

#include "Game.h"
#include "TextureUtil.h"
#include "ContactListener.h"
#include "tinydir.h"
#include "Enemy.h"
#include "Portal.h"



Game::Game(const int width, const int height): window_width_(width), window_height_(height), l(Level("Test")) {
    Game::init();
    Game::load_resources();
}

Game::~Game() {
    SDL_DestroyRenderer(gameRenderer);
    SDL_DestroyWindow(gameWindow);
    gameWindow = NULL;
    gameRenderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

bool Game::run() {
    bool quit = false;
    SDL_Event e;

    float32 timeStep = 1 / 20.0f;   // the length of time passed to simulate (seconds)
    int32 velocityIterations = 8;   // how strongly to correct velocity
    int32 positionIterations = 3;   // how strongly to correct position

    SDL_Rect camera;
    camera.w = window_width_;
    camera.h = window_height_;
    l.go();
    while (!quit) {
	while (SDL_PollEvent (&e) != 0) { // process events
	    if (e.type == SDL_QUIT) { // the exit event
		quit = true; // break out of the loop
	    }
	    if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) { // process key presses
		if (e.key.keysym.sym == 'r') { // reset the level
		    l.reset();
		    load_resources();
		    l.go();
		    continue;
		} else { // all other events considered to be level specific
		    l.getPlayerObj()->processEvent(e);
		}
	    }
	}

	if (level_to_ != "") { // change level event
	    l.reset();
	    load_resources();
	    l.go();
	    level_to_ = "";
	    continue;
	}

	// Update the viewport so that the player object is always in the middle
	{
	    const b2Vec2 pos = l.getPlayerObj()->GetBody()->GetPosition();
	    camera.x = (pos.x + (window_width_ / 2)) * -1 + window_width_ ;
	    camera.y = (pos.y + (window_height_ / 2)) * -1 + window_height_;
	}

	if (l.isRunning()) { // progress the box2d state of the world
	    world->Step( timeStep, velocityIterations, positionIterations);
	}
	SDL_RenderClear( gameRenderer ); // render the new state for all objects
	for (auto iterator = l.worldObjects.begin(); iterator != l.worldObjects.end(); iterator++) {
	    GameBody* g = iterator->second;
	    if (g->isDead()) {
		bool to_remove = g->Die();
		if (to_remove) {
		    // the thing is dead. kill it. remove the body from the set
		}
	    }
	    SDL_Rect pos = g->GetPosRect();
	    const SDL_Rect dim = g->GetTexRect();
	    pos.x += camera.x;
	    pos.y += camera.y;
	    SDL_RenderCopy(gameRenderer,
			   textureMap[g->GetTexture()],
			   &dim,
			   &pos);
	}

	GameBody* g = l.getPlayerObj(); // draw the player last
	if (g->isDead()) {
	    bool to_remove = g->Die();
	    if (to_remove) {
		l.pause();
	    }
	}
	SDL_Rect pos = g->GetPosRect();
	const SDL_Rect dim = g->GetTexRect();

	if (pos.y > 1000) {
	    g->Die();
	    continue;
	}

	// update the camera
	pos.x += camera.x;
	pos.y += camera.y;

	SDL_RenderCopy(gameRenderer,
		       textureMap[g->GetTexture()],
		       &dim,
		       &pos);
	SDL_RenderPresent(gameRenderer);
    }

    return true;
}

void Game::init() {


    // initialize the sdl wideo drivers
    if (SDL_Init (SDL_INIT_VIDEO) < 0) {
	std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n" << std::endl;
	throw "SDL error";
    }

    // create a window
    gameWindow = SDL_CreateWindow ("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				   window_width_, window_height_, SDL_WINDOW_SHOWN);
    if (gameWindow == NULL) {
	std::cout << "SDL could not create the window! SDL_Error: " << SDL_GetError() << std::endl;
	throw "SDL error";
    }

    // create the renderer
    gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gameRenderer == NULL) {
	std::cout << "SDL couldn't initialize the game renderer! SDL_Error: "
		  << SDL_GetError() << std::endl;
	throw "SDL error";
    }

    // set the default params
    SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    int img_init_status = IMG_Init(IMG_INIT_PNG);
    if (!img_init_status) {
	std::cout << "SDL image couldn't be loaded. SDL_Error: "
		  << IMG_GetError() << std::endl;
    }
}

void Game::load_resources() {
    b2Vec2 gravity(0.0f, 9.8f); // word gravity
    world = new b2World(gravity); // create the world

    // the custom contact listener
    ContactListener* contactListener = new ContactListener();
    world->SetContactListener(contactListener);

    // load the textures for all entities
    if (!resources_loaded_) {
	tinydir_dir dir;
	tinydir_open(&dir, "resources/");
	while (dir.has_next)
	{
	    tinydir_file file;
	    if ((tinydir_readfile(&dir, &file) == -1) || (tinydir_next(&dir) == -1))
	    {
		std::cout << "Error getting file" << std::endl;
	    }
	    if (!file.is_dir)
	    {
		SDL_Texture* tex = TextureUtil::loadTexture(gameRenderer, "resources/"+std::string(file.name));
		textureMap[std::string(file.name).substr(0, std::string(file.name).size() - 4)] = tex;
		std::cout << file.name << std::endl;
	    }
	}

	resources_loaded_ = true;
    }

    l.setPlayerObj(new Player(world, "player", b2Vec2(60, 20), b2Vec2(32, 32), 1, 0.0, 0, 3, 5));

    // instantiate the level creatures
    GameBody* g;
    g = new Enemy(world, "simple", b2Vec2(20, 20), b2Vec2(32, 32), 1, 0.3, 1.0, 100, 5);
    l.addObject("box", g);

    g = new GameBody(world, "simple", b2Vec2(0, 250), b2Vec2(250, 32));
    l.addObject("box2", g);

    g = new Portal(world, "portal", b2Vec2(110, 100), b2Vec2(32, 32), this, "Level2");
    l.addObject("portal", g);

    SDL_Texture* tex = TextureUtil::createTextTexture(gameRenderer, "Hello", 24);
    b2Vec2 pos = {20, 20};
    l.texts.push_back(std::make_tuple(tex, pos));

}

bool Game::triggerLoadLevel(std::string to) {
     level_to_ = to;
 }
