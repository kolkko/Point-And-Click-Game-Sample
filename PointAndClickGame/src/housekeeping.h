#ifndef HOUSEKEEPING_H
#define HOUSEKEEPING_H

#include <iostream>
#include <string>
#include "SDL2/SDL.h"

class Housekeeping {
    public:
        void logSDLError(const std::string &msg);
        void cleanUp(SDL_Texture *img1, SDL_Renderer *ren, SDL_Window *win);
        void cleanUpTexture(SDL_Texture *img1);
        void cleanUpRenWin(SDL_Renderer *ren, SDL_Window *win);
};

#endif