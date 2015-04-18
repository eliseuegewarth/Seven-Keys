/*
 * Implementação da classe que representa um jogo utilizando a SDL.
 *
 * Autor: Edson Alves
 * Data: 26/03/2015
 * Licença: LGPL. Sem copyright.
 */
#include "game.h"
#include "map.h"
#include "draw.h"

#include <iostream>
#include <SDL/SDL.h>

using namespace std;

//Função para desenhar retangulos
void FillRect(int x, int y, int w, int h, int color, SDL_Surface *screen) {
	
    SDL_Rect rect = {x,y,w,h};
    SDL_FillRect(screen, &rect, color);
}

// Game Constructor
Game::Game()
{
    
}

// Game Destructor
Game::~Game()
{
}

int Game::run()
{

	// Initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }
    
    // To make sure SDL cleans up before exit
    atexit(SDL_Quit);	
    
    // Create a new window
    SDL_Surface *screen = SDL_SetVideoMode(800, 600, 16,SDL_HWSURFACE|SDL_DOUBLEBUF);
	
	if ( !screen )
    {
        printf("Unable to set 800x600 video: %s\n", SDL_GetError());
        return 1;
    }

    // Creating map
    Map::room * rooms = map.GenerateMap();
    Map::room * currentRoom = rooms;

    // Drawing map
    draw.drawMap(rooms, screen);
    
	// Program main loop
    bool done = false;

    while (not done)
    {
        update_timestep();
        runIA();
        runPhysics();
        done = update();
        done = process_input(&currentRoom, screen);
        //SDL_Delay(500);
        SDL_Flip(screen);
    }

    return 0;
}

void Game::update_timestep()
{
}

bool Game::process_input(Map::room ** currentRoom, SDL_Surface *screen)
{
	// Message processing loop
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        // Check for messages
        switch (event.type)
        {
		    // Exit if the window is closed
		    case SDL_QUIT:
		        return true;
		        break;

		    // Check for keypresses
            case SDL_KEYDOWN:
                /* Check the SDLKey values and move change the coords */
                switch( event.key.keysym.sym )
                {
                    case SDLK_LEFT:
                        if((*currentRoom)->left != NULL)
                        {
                            *currentRoom = (*currentRoom)->left;
                            draw.drawRoom(*currentRoom, screen);
                        }
                        break;
                    case SDLK_RIGHT:
                        if((*currentRoom)->right != NULL)
                        {
                            *currentRoom = (*currentRoom)->right;
                            draw.drawRoom(*currentRoom, screen);
                        }
                        break;
                    case SDLK_UP:
                        if((*currentRoom)->top != NULL)
                        {
                            *currentRoom = (*currentRoom)->top;
                            draw.drawRoom(*currentRoom, screen);
                        }
                        break;
                    case SDLK_DOWN:
                        if((*currentRoom)->bot != NULL)
                        {
                            *currentRoom = (*currentRoom)->bot;
                            draw.drawRoom(*currentRoom, screen);
                        }
                        break;
                }
        }
    }
    return false;
}

void Game::runIA()
{
}

void Game::runPhysics()
{
}

bool Game::update()
{
    return false;
}

/*void Game::draw(SDL_Surface *screen)
{
	// Clear screen
    SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 0, 0, 0));
    
  	// Draw rectangle Example
  	FillRect(50,150,50,50,0xFFFFFF,screen); // White Rect
    FillRect(50+1,150+1,48,48,0x0,screen);	//Black Rect
    SDL_Flip(screen);
}*/
