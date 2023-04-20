#pragma once
#include "Object.h"

class Bird : public Object
{
public:
    int getYpos();
    void Gravity();
    void GetJumpTime();
    void Jump();
    bool JumpState();
    void Reset();

    void CreateTexture1(string path, SDL_Renderer* ren);
    void CreateTexture2(string path, SDL_Renderer* ren);
    void Render(SDL_Renderer* ren);

private:
    double gravity = 0.5;
    int Ypos = 255;
    double acceleratorG = 0;

    bool inJump = false;
    double jumpHeight = -8.5;
    double jumpTimer;
    double lastJump = 0;

    SDL_Texture* Tex1;
    SDL_Texture* Tex2;
    int animationTimer = 0;

};
