#include "Gameloop.h"
#include <iostream>

using namespace std;

Gameloop::Gameloop()
{
    gWindow = NULL;
    gRenderer = NULL;
    GameState = false;

    p.setSrc(0, 0, 24, 32);
	p.setDest(25, 400, 28, 38);

	Pipe_Above1.setSrc(0, 0, 320, 52);
	Pipe_Above1.setDest(400, -200, 400, 52);
	Pipe_Below1.setSrc(0, 0, 320, 52);
	Pipe_Below1.setDest(400, 350, 400, 52);

	Pipe_Above2.setSrc(0, 0, 320, 52);
	Pipe_Above2.setDest(700, -200, 400, 52);
	Pipe_Below2.setSrc(0, 0, 320, 52);
	Pipe_Below2.setDest(700, 350, 400, 52);

	Pipe_Above3.setSrc(0, 0, 320, 52);
	Pipe_Above3.setDest(1000, -200, 400, 52);
	Pipe_Below3.setSrc(0, 0, 320, 52);
	Pipe_Below3.setDest(1000, 350, 400, 52);
}

Gameloop::~Gameloop()
{

}

bool Gameloop:: getGameState()
{
    return GameState;
}

void Gameloop::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    gWindow = SDL_CreateWindow("Flappy Bird v1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT , SDL_WINDOW_SHOWN);
    if( gWindow == NULL)
    {
        cout << "Fail to create Window" << SDL_GetError() << endl;
    }
    else
    {
        gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED);
        if( gRenderer == NULL)
        {
            cout << "renderer not create" << endl;
        }
        else
        {
            //Start render texture
            cout << " success " << endl;
            GameState = true;

            //bird and background
            p.CreateTexture("Image/yellowbird1.png", gRenderer);
			p.CreateTexture1("Image/yellowbird2.png", gRenderer);
			p.CreateTexture2("Image/yellowbird3.png", gRenderer);

			b.CreateTexture("Image/2224_dark.png", gRenderer);

			//pipe
			Pipe_Above1.CreateTexture("Image/Pipe_Above.png", gRenderer);
			Pipe_Below1.CreateTexture("Image/Pipe_Below.png", gRenderer);
			Pipe_Above2.CreateTexture("Image/Pipe_Above.png", gRenderer);
			Pipe_Below2.CreateTexture("Image/Pipe_Below.png", gRenderer);
			Pipe_Above3.CreateTexture("Image/Pipe_Above.png", gRenderer);
			Pipe_Below3.CreateTexture("Image/Pipe_Below.png", gRenderer);

        }
    }
    if(Mix_Init(1) == 0)
    {
        cout << "Sound fail" << Mix_GetError() << endl;
    }
    else
    {
       wingSound = Mix_LoadWAV("sound/flap.wav");
       hitSound = Mix_LoadWAV("sound/hit.wav");
    }
}

void Gameloop::Event()
{
    p.GetJumpTime();
    SDL_PollEvent( &e);
    if(e.type == SDL_QUIT)
    {
        GameState = false;
    }
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        if(e.key.keysym.sym == SDLK_SPACE)
        {
            Mix_VolumeChunk(wingSound, 20);
            Mix_PlayChannel(1, wingSound, 0);
            if(!p.JumpState())
            {
                p.Jump();
            }
            else
            {
                p.Gravity();
            }
        }
    }
    else
    {
        p.Gravity();
    }

}

void Gameloop::Update()
{
    bool flag1 = false;
    bool flag2 = false;

    flag1 = Pipe_Above1.Pipe_Above1Update(variance1);
    flag2 = Pipe_Below1.Pipe_Below1Update(variance1);
    if(flag1 && flag2)
    {
        srand(SDL_GetTicks());
        variance1 = rand() % 200 - 100;
        Pipe_Above1.Pipe_Above1Update(variance1);
        Pipe_Below1.Pipe_Below1Update(variance1);
    }

    flag1 = Pipe_Above2.Pipe_Above2Update(variance2);
    flag2 = Pipe_Below2.Pipe_Below2Update(variance2);
    if(flag1 && flag2)
    {
        srand(SDL_GetTicks());
        variance2 = rand() % 200 - 100;
        Pipe_Above2.Pipe_Above2Update(variance2);
        Pipe_Below2.Pipe_Below2Update(variance2);
    }

    flag1 = Pipe_Above3.Pipe_Above3Update(variance3);
    flag2 = Pipe_Below3.Pipe_Below3Update(variance3);
    if(flag1 && flag2)
    {
        srand(SDL_GetTicks());
        variance3 = rand() % 200 - 100;
        Pipe_Above3.Pipe_Above3Update(variance3);
        Pipe_Below3.Pipe_Below3Update(variance3);
    }

    CollisionDetection();
}

void Gameloop::CollisionDetection()
{
    if(CollisionCheck::CheckCollision(&p.getDest(), &Pipe_Above1.getDest()) ||
       CollisionCheck::CheckCollision(&p.getDest(), &Pipe_Below1.getDest()) ||
       CollisionCheck::CheckCollision(&p.getDest(), &Pipe_Above2.getDest()) ||
       CollisionCheck::CheckCollision(&p.getDest(), &Pipe_Below2.getDest()) ||
       CollisionCheck::CheckCollision(&p.getDest(), &Pipe_Above3.getDest()) ||
       CollisionCheck::CheckCollision(&p.getDest(), &Pipe_Below3.getDest()) )
    {
        Mix_VolumeChunk(hitSound, 20);
        Mix_PlayChannel(1, hitSound, 0);
        SDL_Delay(750);
        Reset();
    }

    if(p.getDest().y > SCREEN_HEIGHT)
    {
        Mix_VolumeChunk(hitSound, 20);
        Mix_PlayChannel(1, hitSound, 0);
        SDL_Delay(750);
        Reset();
    }

}

void Gameloop::Reset()
{
    variance1 = rand() % 200 - 100;
    variance2 = rand() % 200 - 100;
    variance3 = rand() % 200 - 100;

    p.Reset();

    Pipe_Above1.Reset();
    Pipe_Below1.Reset();
    Pipe_Above2.Reset();
    Pipe_Below2.Reset();
    Pipe_Above3.Reset();
    Pipe_Below3.Reset();
}

void Gameloop::Render()
{
    SDL_RenderClear( gRenderer);

    b.Render( gRenderer);

    Pipe_Above1.PipeRender( gRenderer);
    Pipe_Below1.PipeRender( gRenderer);
    Pipe_Above2.PipeRender( gRenderer);
    Pipe_Below2.PipeRender( gRenderer);
    Pipe_Above3.PipeRender( gRenderer);
    Pipe_Below3.PipeRender( gRenderer);

    p.Render( gRenderer);

    SDL_RenderPresent( gRenderer);
}

void Gameloop::Clear()
{
    SDL_RenderClear( gRenderer);
    SDL_DestroyWindow( gWindow);

    gRenderer = NULL;
    gWindow = NULL;

    SDL_Quit();
    IMG_Quit();
    Mix_Quit();

}
