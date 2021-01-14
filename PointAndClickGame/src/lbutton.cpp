#include "lbutton.h"

LButton::LButton() {
    mPosition.x = 0;
    mPosition.y = 0;

    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void LButton::setPosition( int x, int y ) {
    mPosition.x = x;
    mPosition.y = y;
}

int LButton::handleEvent( SDL_Event* e, SDL_Point item_position ) {
    int currentSprite = 0;
    //If mouse event happened
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN ) {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
        //Check if mouse is in button
        bool inside = true;

        mPosition.x = item_position.x;
        mPosition.y = item_position.y;
        //Mouse is left of the button
        if( x < mPosition.x ) {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > mPosition.x + BUTTON_WIDTH ) {
            inside = false;
        }
        //Mouse above the button
        else if( y < mPosition.y ) {
            inside = false;
        }
        //Mouse below the button
        else if( y > mPosition.y + BUTTON_HEIGHT ) {
            inside = false;
        }   

        //Mouse is outside button
        if( !inside ) {
            currentSprite = 0;
        }
        //Mouse is inside button
        else {
            //Set mouse over sprite
            switch( e->type ) {
                case SDL_MOUSEMOTION:
                currentSprite = 1;
                break;
            
                case SDL_MOUSEBUTTONDOWN:
                currentSprite = 2;
                break;
                
            }
        }
    }
    return currentSprite;
}   
