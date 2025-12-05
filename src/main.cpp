#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include "../include/game.hpp"
#include "../include/animation.hpp"
#include <vector>

trauma_state state(NULL, NULL);

int main(int argc, char *argv[]){

    //initialise game
    if(!initialise(state)){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Crash error", "Trauma-demo has crashed and was force to quite.\n contact me at 237672446810 for support and bug fixes", nullptr);
        return 1;
    }

    //Load game assets
    SDL_Texture *idle_texture = IMG_LoadTexture(state.renderer, "/home/pharel/Projects/trauma-demo/assets/idle.png");
    SDL_SetTextureScaleMode(idle_texture, SDL_SCALEMODE_NEAREST);
    
    //setup game data
    const bool *keys = SDL_GetKeyboardState(nullptr);
    float playerX = 150;
    const float floor = state.WINDOW_LOGICAL_HEIGHT;
    uint64_t prevTime = SDL_GetTicks();
    bool flipHorizontal = false;

    //start the game loop
    bool running = true;
    while (running)
    {
        uint64_t nowTime = SDL_GetTicks();
        float deltaTime = (nowTime - prevTime)/1000.0f;
        SDL_Event event{ 0 };
        //process inputs
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

        //update (hable movements)
        float moveAmount = 0;
        if(keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]){
            flipHorizontal = true;
            moveAmount -= 75.f;
        }

        if(keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]){
            flipHorizontal = false;
            moveAmount += 75.f;
        }
        playerX += moveAmount*deltaTime;


        //render
        SDL_SetRenderDrawColor(state.renderer, 211, 211, 211, 211);
        SDL_RenderClear(state.renderer);

        SDL_FRect sprite_src {
            .x = 0,
            .y = 0,
            .w = 23,
            .h = 35
        };

        SDL_FRect sprite_dest {
            .x = playerX,
            .y = floor - 31,
            .w = 32,
            .h = 32
        };

        SDL_RenderTextureRotated(state.renderer, idle_texture, &sprite_src, &sprite_dest, 0, nullptr, (flipHorizontal) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

        SDL_RenderPresent(state.renderer);

        prevTime = nowTime;
    }

    SDL_DestroyTexture(idle_texture);
    cleanup(state);
    return 0;
}

