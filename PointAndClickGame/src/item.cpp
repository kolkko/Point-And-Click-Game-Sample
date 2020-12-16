#include "item.h"

Item::Item(std::string name, std::string description, int xPosition, int yPosition, int w, int h, SDL_Texture *sheet) {
    _name = name;
    _description = description;
	_itemPosition.x = xPosition;
	_itemPosition.y = yPosition;
    _w = w;
    _h = h;
    _spriteSheet = sheet;
}

std::string Item::itemName() {
    return _name;
}
std::string Item::itemDescription() {
    return _description;
}

int Item::xPosition() {
    return _itemPosition.x;
}

int Item::yPosition() {
    return _itemPosition.y;
}

void Item::renderItem(SDL_Renderer *ren) {
    	SDL_Rect clip;
		clip.h = _h;
		clip.w = _w;
		if (whichClip == 0){
		clip.x = 0;
		clip.y = 0;
		}
		else if (whichClip == 1 || whichClip == 2){
		clip.x = 200;
		clip.y = 0;
		}
	std::cout << _name << ": " << whichClip << clip.x << std::endl;
    renderTexture(_spriteSheet, ren, _itemPosition.x, _itemPosition.y, &clip);
}