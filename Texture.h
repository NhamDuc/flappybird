#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

using namespace std;
class Texture
{
public:
	static SDL_Texture* loadFromFile(string path, SDL_Renderer* ren);
};
