#include "Game.h"

Game::Game(const int width, const int height) {
    window_width = width;
    window_height = height;

    Game::init();
    Game::load_resources();
}

Game::~Game() {

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
	SDL_FillRect(gameScreenSurface, NULL, 0xFFFFFF);
	SDL_UpdateWindowSurface(gameWindow);
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
	std::cout << "SDL could not create the window! SDL_Error: " << SDL_GetError() << "\n" << std::endl;
	throw "SDL error";
    }
    else {
	gameScreenSurface = SDL_GetWindowSurface (gameWindow);
    }

}

void Game::load_resources() {
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = this->world->CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);
}
