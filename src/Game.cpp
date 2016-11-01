#include "Game.h"
#include "TextureUtil.h"


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

    while (!quit) {
	while (SDL_PollEvent (&e) != 0) {
	    if (e.type == SDL_QUIT) {
		quit = true;
	    }
	}

	world->Step( timeStep, velocityIterations, positionIterations);
	SDL_RenderClear( gameRenderer );
	for (auto iterator = l.worldObjects.begin(); iterator != l.worldObjects.end(); iterator++) {
	    GameBody* g = iterator->second;
	    const SDL_Rect pos = g->GetPosRect();
	    const SDL_Rect dim = g->GetTexRect();
	    SDL_RenderCopy(gameRenderer,
			   textureMap[g->GetTexture()],
			   &dim,
			   &pos);
	}
	SDL_RenderPresent(gameRenderer);
    }

    return true;
}

void Game::init() {
    b2Vec2 gravity(0.0f, 9.8f);
    world = new b2World(gravity);

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
    SDL_Texture* tex = TextureUtil::loadTexture(gameRenderer, "/resources/simple.png");
    textureMap["simple"] = tex;

    GameBody* g = new GameBody(world, "simple", b2Vec2(20, 20), b2Vec2(32, 32), 1, 0.3, 1.0);
    l.addObject("box", g);
    g = new GameBody(world, "simple", b2Vec2(0, 250), b2Vec2(250, 32));
    l.addObject("box2", g);
}
