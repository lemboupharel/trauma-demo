#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "../include/game.hpp"

trauma_state state(NULL, NULL);

int main(int argc, char *argv[]){

    //initialise game
    if(!initialise(state)){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Crash error", "Trauma-demo has crashed and was force to quite.\n contact me at 237672446810 for support and bug fixes", nullptr);
    }

    //Load game assets
    SDL_Texture *idle_texture = IMG_LoadTexture(state.renderer, "/home/pharel/Projects/trauma-demo/assets/idle.png");
    SDL_SetTextureScaleMode(idle_texture, SDL_SCALEMODE_NEAREST);
    
    //setup game data

    //start the game loop
    bool running = true;

    while (running)
    {
        //process inputs
        SDL_Event event{ 0 };
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                if (event.key.key == SDLK_ESCAPE)
                    running = false;
                break;
            case SDL_EVENT_WINDOW_RESIZED:
                state.WINDOW_WIDTH = event.window.data1;
                state.WINDOW_HEIGHT = event.window.data2;
                std::cout << "Width: " << state.WINDOW_WIDTH << " Height: " << state.WINDOW_HEIGHT << std::endl;
                break;
            }
        }

        //update


        //render
        SDL_SetRenderDrawColor(state.renderer, 211, 211, 211, 211);
        SDL_RenderClear(state.renderer);

        SDL_FRect sprite {
            .x = 0,
            .y = 0,
            .w = 21,
            .h = 31
        };

        SDL_FRect drawSprite {
            .x = 2,
            .y = 2,
            .w = 21,
            .h = 31
        };

        SDL_RenderTexture(state.renderer, idle_texture, &sprite, &drawSprite);

        SDL_RenderPresent(state.renderer);
         
    }

    SDL_DestroyTexture(idle_texture);
    cleanup(state);
    return 0;
}

