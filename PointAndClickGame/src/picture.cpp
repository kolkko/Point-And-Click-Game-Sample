#include "picture.h"

// Loads an image into a texture on the rendering device
// return the loaded texture, or nullptr if something went wrong.
SDL_Texture* Picture::loadTexture(const std::string &file, SDL_Renderer *ren){
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr){
        Housekeeping hk;
		hk.logSDLError("loadTexture");
	}
	return texture;
}

// Draw a texture to a renderer at some destination dst
// taking a clip if desired
void Picture::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, SDL_Rect dst, SDL_Rect *clip){
	SDL_RenderCopy(ren, tex, clip, &dst);
}

// Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving the texture's
// width and height and taking a clip of the texture if desired
void Picture::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, SDL_Rect *clip){
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	if(clip != nullptr){
		dst.w = clip->w;
		dst.h = clip->h;	
	}
	else{
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}
	renderTexture(tex, ren, dst, clip);
}