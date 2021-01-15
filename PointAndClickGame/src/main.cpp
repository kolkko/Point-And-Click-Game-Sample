#include <iostream>
#include <string>
#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"
#include "housekeeping.h"
#include "text.h"
#include "picture.h"
#include "item.h"
#include "lbutton.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const std::string DEFAULT_FONT = "Langar-Regular.ttf";
const int DEFAULT_FONT_SIZE = 30;
const std::string DEFAULT_TEXT = "Hover over objects to see descriptions.";
Housekeeping hk;

// Item interaction logic
std::string a = "NONE";
std::string b = "NONE";

std::string checkLogic(std::string &a, std::string &b, std::vector<Item> &items) {
	std::string description = "Incorrect!";
	if (a == "Key" && b == "Keyhole") {
		std::cout << "Correct!" << std::endl;
		description = "Correct!";
	}
	else if (a == "Keyhole" && b == "Key") {
			std::cout << "Correct!" << std::endl;
			description = "Correct!";
	}
	else {
		std::cout << "Incorrect" << std::endl;
		description = "Incorrect!";
	}

	a = "NONE";
	b = "NONE";
	for (auto & item : items) {
		item.whichClip = 0;
	}
return description;
}

// Set text to display
std::string setText(std::vector<Item> items) {
	std::string description;
	bool hover;
	bool selected;
	// Is an item selected? Is an item being hovered over?
	for (auto & item : items) {
		if (item.whichClip == 1) {
			hover = true;
			description = item.itemDescription();
		}
		else if (item.whichClip == 2) {
			selected = true;
		}
	}
	// Hover gets precedence over other text
	if (hover) {
		return description;
	}
	else if (selected) {
		description = "Item selected.";
		return description;
	}
	else {
		description = DEFAULT_TEXT;
		return description;
	}
}

// Rubric point: The project demonstrates an understanding of C++ functions and control structures.
int main(int, char**) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		hk.logSDLError("SDL_Init Error: ");
		return 1;
	}

	if (TTF_Init() != 0){
		hk.logSDLError("TTF_Init");
		SDL_Quit();
		return 1;
	}
			
	SDL_Window *win = SDL_CreateWindow("Point and Click Game", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		hk.logSDLError("SDL_CreateWindow Error: ");
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		hk.logSDLError("SDL_CreateRenderer Error: ");
		SDL_Quit();
		return 1;
	}

	const std::string resPath = "../resources/";
	
	// Load textures
	Picture graphics;
	SDL_Texture *background = graphics.loadTexture(resPath + "room.png", ren);
	SDL_Texture *sprites_item1 = graphics.loadTexture(resPath + "item1.png", ren);
	SDL_Texture *sprites_item2 = graphics.loadTexture(resPath + "item2.png", ren);
	SDL_Texture *sprites_item3 = graphics.loadTexture(resPath + "item3.png", ren);

	// If there's an error, clean all up
	if (background == nullptr || sprites_item1 == nullptr || sprites_item2 == nullptr
		|| sprites_item3 == nullptr){
		hk.cleanUp(background, ren, win);
		SDL_Quit();
		return 1;
	}

	// Create items and store all in a vector
	std::vector<Item> items;
	Item item1("Key", "A large brass key, hanging on the wall.", 640, 235, 110, 110, sprites_item1);
	items.push_back(item1);
	Item item2("Keyhole", "A keyhole in a sturdy wood door.", 492, 290, 110, 110, sprites_item2);
	items.push_back(item2);
	Item item3("Feather", "A white ostrich feather.", 262, 501, 110, 110, sprites_item3);
	items.push_back(item3);

	// Set up default text 
	// Color is in RGBA format
	SDL_Color color = { 0, 0, 0, 0 };
	Text boxText;
	SDL_Texture *boxTexture = boxText.renderText(DEFAULT_TEXT, resPath + DEFAULT_FONT, color, DEFAULT_FONT_SIZE, ren);

	SDL_Event e;
	LButton mouse;
	bool quit = false;
	std::string descText = DEFAULT_TEXT;
	while (!quit){
		// Rubric point: The project accepts user input and processes the input.
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
				quit = true;
			}
			if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN ) {
				for(auto & item : items) {
					SDL_Point item_position;
					item_position.x = item.xPosition();
					item_position.y = item.yPosition();
					// Check if item is already selected, if not, handle event
					if (item.whichClip != 2) {
						item.whichClip = mouse.handleEvent(&e, item_position);
					}
					// If item is selected, set selection variables
					if (item.whichClip == 2) {
						if (a == "NONE") {
							a = item.itemName();
						}
						else if (b == "NONE" && a != item.itemName()) {
							b = item.itemName();
						}
					}
				}
				descText = setText(items);
				// Check if 2 items are selected
				if (a != "NONE" && b != "NONE") {
					std::cout << "Checking logic" << std::endl;
					descText = checkLogic(a, b, items);
				}
			}	
			SDL_RenderClear(ren);
			graphics.renderTexture(background, ren, 0, 0);	
			// Render item and box text
			for(auto & item : items) {
				item.renderItem(ren);
			}
			boxTexture = boxText.renderText(descText, resPath + DEFAULT_FONT, color, DEFAULT_FONT_SIZE, ren);
			Picture displayText;
			displayText.renderTexture(boxTexture, ren, 10, 10);
			SDL_RenderPresent(ren);
		}
	}

	hk.cleanUpTexture(background);
	for (auto & item : items) {
		hk.cleanUpTexture(item.texture());
	}
	hk.cleanUpRenWin(ren, win);
	TTF_Quit();
	SDL_Quit();
}