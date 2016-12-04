#include <string>

#include "Game.h"
#include "TextureUtil.h"
#include "ContactListener.h"
#include "tinydir.h"
#include "Enemy.h"



Game::Game(const int width, const int height): window_width(width), window_height(height), l(Level("Test")) {
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
    camera.w = window_width;
    camera.h = window_height;
    l.go();
    while (!quit) {
	while (SDL_PollEvent (&e) != 0) {
	    if (e.type == SDL_QUIT) {
		quit = true;
	    }
	    if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
		if (e.key.keysym.sym == 'r') {
		    l.reset();
		    load_resources();
		    l.go();
		    continue;
		} else {
		    l.getPlayerObj()->processEvent(e);
		}
	    }
	}

	// Update the viewport so that the player object is always in the middle
	{
	    const b2Vec2 pos = l.getPlayerObj()->GetBody()->GetPosition();
	    camera.x = (pos.x + (window_width / 2)) * -1 + window_width ;
	    camera.y = (pos.y + (window_height / 2)) * -1 + window_height;
	}

	if (l.isRunning()) {
	    world->Step( timeStep, velocityIterations, positionIterations);
	}
	SDL_RenderClear( gameRenderer );
	for (auto iterator = l.worldObjects.begin(); iterator != l.worldObjects.end(); iterator++) {
	    GameBody* g = iterator->second;
	    if (g->isDead()) {
		bool to_remove = g->Die();
		if (to_remove) {
		    // remove the body from the set
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

	GameBody* g = l.getPlayerObj();
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



    if (SDL_Init (SDL_INIT_VIDEO) < 0) {
	std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n" << std::endl;
	throw "SDL error";
    }

    gameWindow = SDL_CreateWindow ("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				   window_width, window_height, SDL_WINDOW_SHOWN);
    if (gameWindow == NULL) {
	std::cout << "SDL could not create the window! SDL_Error: " << SDL_GetError() << std::endl;
	throw "SDL error";
    }

    gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gameRenderer == NULL) {
	std::cout << "SDL couldn't initialize the game renderer! SDL_Error: "
		  << SDL_GetError() << std::endl;
	throw "SDL error";
    }
    SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    int img_init_status = IMG_Init(IMG_INIT_PNG);
    if (!img_init_status) {
	std::cout << "SDL image couldn't be loaded. SDL_Error: "
		  << IMG_GetError() << std::endl;
    }
}

void Game::load_resources() {
    b2Vec2 gravity(0.0f, 9.8f);
    world = new b2World(gravity);
    ContactListener* contactListener = new ContactListener();
    world->SetContactListener(contactListener);

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

    GameBody* g;
    g = new Enemy(world, "simple", b2Vec2(20, 20), b2Vec2(32, 32), 1, 0.3, 0.0, 100, 5);
    l.addObject("box", g);

    g = new GameBody(world, "simple", b2Vec2(0, 250), b2Vec2(250, 32));
    l.addObject("box2", g);

    g = new GameBody(world, "simple", b2Vec2(300, 250), b2Vec2(250, 32));
    l.addObject("box3", g);

    g = new GameBody(world, "simple", b2Vec2(350, 150), b2Vec2(250, 32));
    l.addObject("box4", g);

    g = new GameBody(world, "simple", b2Vec2(450, 250), b2Vec2(250, 32));
    l.addObject("box5", g);

    g = new GameBody(world, "simple", b2Vec2(600, 250), b2Vec2(250, 32));
    l.addObject("box6", g);
}
