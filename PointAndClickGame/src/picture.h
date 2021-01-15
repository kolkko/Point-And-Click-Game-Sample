#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "housekeeping.h"

class Picture {
    public:
        SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
        // Rubric point: Overloaded functions allow the same function to operate on different parameters.
        void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst, SDL_Rect *clip = nullptr);
        void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip = nullptr);
    private:
        
};

#endif