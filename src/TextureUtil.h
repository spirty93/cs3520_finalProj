#ifndef TEXTURE_UTIL_H
#define TEXTURE_UTIL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

/*
 * Utility class handeling the texture creation
 */
class TextureUtil {
 public:
    /*
     * @param gameRenderer the game renderer where texture will be displayed
     * @param path the path to texture
     * load texture from file.
     */
    static SDL_Texture* loadTexture(SDL_Renderer* gameRenderer, const std::string path);
    /*
     * @param gameRenderer the game renderer where texture will be displayed
     * @param text the text to be displayed in picture
     * create texture from string.
     */
    static SDL_Texture* createTextTexture(SDL_Renderer* gameRenderer, const std::string text, const int size);
 private:
    TextureUtil() {};
    ~TextureUtil() {};
};

#endif
