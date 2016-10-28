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
    while (!quit) {
	while (SDL_PollEvent (&e) != 0) {
	    if (e.type == SDL_QUIT) {
		quit = true;
	    }
	}
	SDL_RenderClear( gameRenderer );
	auto tex = textureMap["simple"];
	SDL_Rect r;
	r.x = 20;
	r.y = 20;
	r.w = 52;
	r.h = 52;
	SDL_RenderCopy(gameRenderer, tex, NULL, &r);
	for (auto iterator = l.worldObjects.begin(); iterator != l.worldObjects.end(); iterator++) {
	    GameBody* g = iterator->second;
	    const SDL_Rect pos = g->GetPosRect();
	    //const SDL_Rect dim = g->GetTexRect();
	    SDL_RenderCopy(gameRenderer,
			   textureMap["simple"],
			   NULL,
			   &pos);
	}
	SDL_RenderPresent( gameRenderer );
    }

    return true;
}

void Game::init() {
    b2Vec2 gravity(0.0f, 10.0f);
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

    GameBody* g = new GameBody(world, "simple", b2Vec2(20, 20), b2Vec2(32, 32));
    l.addObject("box", g);
}
