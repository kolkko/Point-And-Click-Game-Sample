#ifndef LBUTTON_H
#define LBUTTON_H

#include <iostream>
#include <string>
#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "housekeeping.h"
#include "item.h"

class LButton
{
    public:
        //Constructor, initializes internal variables
        LButton();

        //Sets top left position
        void setPosition( int x, int y );

        //Handles mouse event
        int handleEvent( SDL_Event* e, SDL_Point item_position );
    
        //Shows button sprite
        //void render();

        //Button constants
        const int BUTTON_WIDTH = 110;
        const int BUTTON_HEIGHT = 110;
        const int TOTAL_BUTTONS = 4;

        enum LButtonSprite
        {
            BUTTON_SPRITE_MOUSE_OUT = 0,
            BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
            BUTTON_SPRITE_MOUSE_DOWN = 2,
            BUTTON_SPRITE_MOUSE_UP = 3,
            BUTTON_SPRITE_TOTAL = 4
        };

    private:
        //Top left position
        SDL_Point mPosition;

        //Currently used global sprite
        LButtonSprite mCurrentSprite;
};

#endif