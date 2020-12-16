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

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;
const std::string DEFAULT_TEXT = "Hover over objects to see descriptions.";
Housekeeping hk;

// Item interaction logic
std::string a = "NONE";
std::string b = "NONE";

void checkLogic() {
	if (a == "Square") {
		if (b == "Circle") {
			std::cout << "Correct!" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
	}
	if (a == "Circle") {
				if (b == "Triangle") {
			std::cout << "Correct!" << std::endl;
		}
		else {
			std::cout << "Incorrect" << std::endl;
		}
	}

	a = "NONE";
	b = "NONE";
}

// Rubric point: The project demonstrates an understanding of C++ functions and control structures.
int main(int, char**){
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		hk.logSDLError("SDL_Init Error: ");
		return 1;
	}

	if (TTF_Init() != 0){
		hk.logSDLError("TTF_Init");
		SDL_Quit();
		return 1;
	}
			
	SDL_Window *win = SDL_CreateWindow("Point and Click Game", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == nullptr){
		hk.logSDLError("SDL_CreateWindow Error: ");
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		SDL_DestroyWindow(win);
		hk.logSDLError("SDL_CreateRenderer Error: ");
		SDL_Quit();
		return 1;
	}

	const std::string resPath = "../res/PointAndClickGame/";
	
	// Load textures
	Picture graphics;
	SDL_Texture *background = graphics.loadTexture(resPath + "room.png", ren);
	SDL_Texture *sprites_item1 = graphics.loadTexture(resPath + "item1.png", ren);
	SDL_Texture *sprites_item2 = graphics.loadTexture(resPath + "item2.png", ren);

	// Create items and store all in a vector
	std::vector<Item> items;
	Item item1("Square", "This is a square.", 50, 50, 200, 200, sprites_item1);
	items.push_back(item1);
	Item item2("Circle", "This is a circle.", 300, 300, 200, 200, sprites_item2);
	items.push_back(item2);

	//We'll render the string "TTF fonts are cool!" in white
	//Color is in RGBA format
	SDL_Color color = { 166, 71, 221, 1 };
	Text boxText;
	SDL_Texture *boxTexture = boxText.renderText(DEFAULT_TEXT, resPath + "sample.ttf", color, 40, ren);




	// If there's an error, clean all up
	if (background == nullptr){
		hk.cleanUp(background, ren, win);
		SDL_Quit();
		return 1;
	}

	
	SDL_Event e;
	LButton mouse;
	bool quit = false;
	std::string descText = DEFAULT_TEXT;
	while (!quit){
		// Rubric point: The project accepts user input and processes the input.
		while (SDL_PollEvent(&e)){
			if (e.type == SDL_QUIT){
				quit = true;
			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE){
				quit = true;
			}
			if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN ){
				// Determine if item should be highlighted and set text
				descText = DEFAULT_TEXT;
				for(int i = 0; i < items.size(); i++) {
					SDL_Point item_position;
					item_position.x = items[i].xPosition();
					item_position.y = items[i].yPosition();
					items[i].whichClip = mouse.handleEvent(&e, item_position);
					if (items[i].whichClip == 1) {
						descText = items[i].itemDescription();
					}
					else if (items[i].whichClip == 2) {
						descText = "Item selected";
						if (a == "NONE") {
							a = items[i].itemName();
						}
						else if (b == "NONE") {
							b = items[i].itemName();
						}
					}
				}
			}
		}
		SDL_RenderClear(ren);
		graphics.renderTexture(background, ren, 0, 0);	

		// Render item and box text
		for(int i = 0; i < items.size(); i++) {
			items[i].renderItem(ren);
		}
		boxTexture = boxText.renderText(descText, resPath + "sample.ttf", color, 40, ren);
		Picture displayText;
		displayText.renderTexture(boxTexture, ren, 300, 0);

		SDL_RenderPresent(ren);

		// Check if 2 items are selected
		if (a != "NONE" && b != "NONE") {
			checkLogic();
		}
	}

	hk.cleanUpTexture(background);
	hk.cleanUpRenWin(ren, win);
	TTF_Quit();
	SDL_Quit();
}