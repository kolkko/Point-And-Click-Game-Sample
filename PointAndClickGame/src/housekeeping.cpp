#include "housekeeping.h"

// Log an SDL error with some error message to the output stream of our choice
// msg is The error message to write, format will be msg error: SDL_GetError()
void Housekeeping::logSDLError(const std::string &msg){
	std::cout << msg << " error: " << SDL_GetError() << std::endl;
}

// clean up
void Housekeeping::cleanUp(SDL_Texture *img1, SDL_Renderer *ren, SDL_Window *win) {
	SDL_DestroyTexture(img1);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	return;
}

void Housekeeping::cleanUpTexture(SDL_Texture *img1) {
	SDL_DestroyTexture(img1);
	return;
}

void Housekeeping::cleanUpRenWin(SDL_Renderer *ren, SDL_Window *win) {
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	return;
}