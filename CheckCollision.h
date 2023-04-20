#pragma once
#include <SDL.h>
#include <SDL_image.h>

class CollisionCheck
{
public:
    static bool CheckCollision(SDL_Rect* A, SDL_Rect* B);
};
