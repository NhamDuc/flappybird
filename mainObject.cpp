#include "MainObject.h"
#include <iostream>

using namespace std;

void Bird::Render(SDL_Renderer* ren)
{
	animationTimer++;
	if (animationTimer < 16)
	{
		SDL_RenderCopyEx(ren, getTexture(), &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer >= 16 && animationTimer <= 32)
	{
		SDL_RenderCopyEx(ren, Tex1, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer > 32)
	{
		SDL_RenderCopyEx(ren, Tex2, &getSrc(), &getDest(), 0, NULL, SDL_FLIP_NONE);
	}
	if (animationTimer > 48)
	{
		animationTimer = 0;
	}
}


void Bird::CreateTexture1(string path, SDL_Renderer* ren)
{
	Tex1 = Texture::loadFromFile(path, ren);
}

void Bird::CreateTexture2(string path, SDL_Renderer* ren)
{
	Tex2 = Texture::loadFromFile(path, ren);
}

int Bird::getYpos()
{
    return Ypos;
}

void Bird::Gravity()
{
    if(JumpState())
    {
        acceleratorG = acceleratorG + 0.075;
        jumpHeight = jumpHeight + gravity;
        Ypos = Ypos + gravity + acceleratorG + jumpHeight;
        setDest(25, Ypos, 28, 38);
        if(jumpHeight > 0)
        {
            inJump = false;
            jumpHeight = -8.5;
        }
    }
    else
    {
        acceleratorG = acceleratorG + 0.075;
        Ypos = Ypos + gravity + acceleratorG;
        setDest(25, Ypos, 28, 38);
    }
}

void Bird::Jump()
{
    if(jumpTimer - lastJump > 150)
    {
        acceleratorG = 0;
        inJump = true;
        lastJump = jumpTimer;
    }
    else
    {
        Gravity();
    }
}

void Bird::GetJumpTime()
{
    jumpTimer = SDL_GetTicks();
}

bool Bird::JumpState()
{
    return inJump;
}

void Bird::Reset()
{
    acceleratorG = 0;
    Ypos = 255;
    lastJump = 0;
}
