#include "Texture.h"

SDL_Texture* Texture::loadFromFile(string path,SDL_Renderer* ren)
{
	SDL_Surface* surface;
	surface = IMG_Load(path.c_str());
	SDL_Texture* tex;
	tex = SDL_CreateTextureFromSurface(ren, surface);
	return tex;
}
