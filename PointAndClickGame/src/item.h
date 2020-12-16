#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "housekeeping.h"
#include "picture.h"

// Rubric point: The project uses Object Oriented Programming techniques.
class Item : public Picture {
    public:
        // Rubric point: Class constructors utilize member initialization lists.
        Item(std::string name, std::string description, int xPosition, int yPosition, int w, int h, SDL_Texture *sheet);
        // destructor
        // getter
        std::string itemName();
        std::string itemDescription();
        int xPosition();
        int yPosition();

        // render item on screen
        void renderItem(SDL_Renderer *ren);

        // display item (call in constructor)
        // hide item
        // highlight
        // show text
        // useWith
        // use

        int whichClip = 0;

    //private:
        std::string _name;
        std::string _description;
        std::vector<Item> _useWith;
        int _xNormal = 0;
        int _yNormal = 0;
        SDL_Point _itemPosition;
        int _w; 
        int _h;
        SDL_Texture *_spriteSheet;




};

#endif