#include "Background.h"
#include <cstdlib>

void Background::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, getTexture(), NULL, NULL);
}

void Background::PipeRender(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}

bool Background::Pipe_Above1Update(int incY)
{
    this->incY1 = incY;
    if( pipeDistance1 <= -100)
    {
        pipeDistance1 += 950;
        return true;
    }
    else
    {
        pipeDistance1 -= 3;
        setSrc(0, 0, 320, 52);
        setDest(pipeDistance1, -200 + this->incY1, 400, 52);
        return false;
    }
}

bool Background::Pipe_Below1Update(int incY)
{
    this->incY1 = incY;
    if( pipeDistance1 <= -100)
    {
        pipeDistance1 += 950;
        return true;
    }
    else
    {
        pipeDistance1 -= 3;
        setSrc(0, 0, 320, 52);
        setDest(pipeDistance1, 350 + this->incY1, 400, 52);
        return false;
    }
}

bool Background::Pipe_Above2Update(int incY)
{
    this->incY2 = incY;
    if( pipeDistance2 <= -100)
    {
        pipeDistance2 += 950;
        return true;
    }
    else
    {
        pipeDistance2 -= 3;
        setSrc(0, 0, 320, 52);
        setDest(pipeDistance2, -200 + this->incY2, 400, 52);
        return false;
    }
}

bool Background::Pipe_Below2Update(int incY)
{
    this->incY2 = incY;
    if( pipeDistance2 <= -100)
    {
        pipeDistance2 += 950;
        return true;
    }
    else
    {
        pipeDistance2 -= 3;
        setSrc(0, 0, 320, 52);
        setDest(pipeDistance2, 350 + this->incY2, 400, 52);
        return false;
    }
}

bool Background::Pipe_Above3Update(int incY)
{
    this->incY3 = incY;
    if( pipeDistance3 <= -100)
    {
        pipeDistance3 += 950;
        return true;
    }
    else
    {
        pipeDistance3 -= 3;
        setSrc(0, 0, 320, 52);
        setDest(pipeDistance3, -200 + this->incY3, 400, 52);
        return false;
    }
}

bool Background::Pipe_Below3Update(int incY)
{
    this->incY3 = incY;
    if( pipeDistance3 <= -100)
    {
        pipeDistance3 += 950;
        return true;
    }
    else
    {
        pipeDistance3 -= 3;
        setSrc(0, 0, 320, 52);
        setDest(pipeDistance3, 350 + this->incY3, 400, 52);
        return false;
    }
}

int Background::getPipe1Y()
{
    return 200 + this->incY1;
}

int Background::getPipe1X()
{
    return pipeDistance1;
}

int Background::getPipe2Y()
{
    return 300 + this->incY2;
}

int Background::getPipe2X()
{
    return pipeDistance2;
}

int Background::getPipe3Y()
{
    return 300 + this->incY3;
}

int Background::getPipe3X()
{
    return pipeDistance3;
}

void Background::Reset()
{
    pipeDistance1 = 400;
    pipeDistance2 = 650;
    pipeDistance3 = 950;

    incY1 = 0;
    incY2 = 0;
    incY3 = 0;
}
