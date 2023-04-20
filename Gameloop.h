#include "Texture.h"
#include "MainObject.h"
#include "Background.h"
#include "CheckCollision.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include<cstdlib>

using namespace std;

class Gameloop
{
public:
    Gameloop();
    ~Gameloop();

    bool getGameState();

    void Init();
    void Update();
    void Event();
    void Render();
    void Reset();
    void CollisionDetection();
    void Clear();

private:
    const int SCREEN_WIDTH = 900;
    const int SCREEN_HEIGHT = 650;

    Bird p;
    Background b;

    Background Pipe_Above1;
    Background Pipe_Below1;
    Background Pipe_Above2;
	Background Pipe_Below2;
	Background Pipe_Above3;
	Background Pipe_Below3;

	int variance1 = rand() % 200 - 100;
	int variance2 = rand() % 200 - 100;
	int variance3 = rand() % 200 - 100;

    bool GameState;

    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Event e;

    Mix_Chunk* wingSound;
    Mix_Chunk* hitSound;

};
