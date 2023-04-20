#pragma once
#include "Texture.h"

class Object
{
public:
    SDL_Texture* getTexture();
    SDL_Rect& getSrc();
	SDL_Rect& getDest();
    void setSrc(int x, int y, int h, int w);
	void setDest(int x, int y, int h, int w);

    void CreateTexture(string path, SDL_Renderer* ren);
    void virtual Render(SDL_Renderer* ren)=0;
private:
    SDL_Rect src;
    SDL_Rect dest;
    SDL_Texture* Tex;
};
