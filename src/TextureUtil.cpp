#include "TextureUtil.h"

SDL_Texture* TextureUtil::loadTexture(SDL_Renderer* gameRenderer, const std::string path) {
    SDL_Texture* tex = NULL;
    SDL_Surface* surf = IMG_Load(path.c_str());
    if (surf == NULL) {
	std::cout << "Error loading texture. SDL Error: " << IMG_GetError() << std::endl;
	throw "SDL Error";
    }
    tex = SDL_CreateTextureFromSurface(gameRenderer, surf);
    if (tex == NULL) {
	std::cout << "Error creating texture from surface. SDL Error: "
		  << SDL_GetError() << std::endl;
	throw "SDL Error";
    }
    SDL_FreeSurface(surf);

    return tex;
}

SDL_Texture* TextureUtil::createTextTexture(SDL_Renderer* gameRenderer, const std::string text, const int size) {
    TTF_Font* Sans = TTF_OpenFont("Sans.ttf", size);
    SDL_Color Black = {0, 0, 0, 0};
    SDL_Surface* messageSurface = TTF_RenderText_Solid(Sans, text.c_str(), Black);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(gameRenderer, messageSurface);
    SDL_FreeSurface(messageSurface);
    return textTexture;
}
