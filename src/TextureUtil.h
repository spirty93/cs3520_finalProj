#ifndef TEXTURE_UTIL_H
#define TEXTURE_UTIL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class TextureUtil {
 public:
    static SDL_Texture* loadTexture(SDL_Renderer* gameRenderer, const std::string path);
    static SDL_Texture* createTextTexture(SDL_Renderer* gameRenderer, const std::string text, const int size);
 private:
    TextureUtil() {};
    ~TextureUtil() {};
};

#endif
