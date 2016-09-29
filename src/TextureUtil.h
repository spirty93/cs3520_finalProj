#ifndef TEXTURE_UTIL_H
#define TEXTURE_UTIL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class TextureUtil {
 public:
    static SDL_Texture* loadTexture(SDL_Renderer* gameRenderer, const std::string path);
 private:
    TextureUtil() {};
    ~TextureUtil() {};
};

#endif
