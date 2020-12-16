#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "housekeeping.h"

class Text {
    public:
        SDL_Texture* renderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);

    private:
        Housekeeping hk1;
};

#endif