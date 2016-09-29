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
