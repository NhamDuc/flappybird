#include "Gameloop.h"

Gameloop* g = new Gameloop();

int main(int argc, char** argv)
{
    const int FPS = 60;
    const int DELAY = 1000 / FPS;

    double start;
    double current = 0;

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2480);

    g->Init();
    while(g->getGameState())
    {
        g->Event();
        g->Update();
        g->Render();

        start = SDL_GetTicks();
        if(start - current < DELAY)
        {
            SDL_Delay(DELAY-(start - current));
        }
        current = start;

    }
    g->Clear();
    return 0;
}
