#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <SDL3_image/SDL_image.h>

void cleanup();

struct trauma_state
{
    SDL_Window *windows = NULL;
    SDL_Renderer *renderer = NULL;
} state;


int main(int argc, char *argv[]){
    //initialize SDL3
    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error initializing SDL3", nullptr);
        return 1;
    }


    //creating window
    int width = 800;
    int height = 600;

    state.windows = SDL_CreateWindow("SDL3 demo", width, height, 0);
    if(state.windows == NULL){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating SDL3 window", nullptr);
        SDL_Quit();
        return 1;
    }


    //creating render
    state.renderer = SDL_CreateRenderer(state.windows, NULL);
    if(state.renderer == NULL){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating render for window", nullptr);
        cleanup();
        return 1;
    }


    //creating sprite texture
    SDL_Texture *idle_texture = IMG_LoadTexture(state.renderer, "/home/pharel/Projects/trauma-demo/assets/idle.png");
    if (idle_texture == NULL) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "WARRNING", "Can't load game asset", nullptr);
    } else{
        SDL_SetTextureScaleMode(idle_texture, SDL_SCALEMODE_NEAREST);
    }
    

    //start game loop
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
            }
        }

        //update


        //render
        SDL_SetRenderDrawColor(state.renderer, 255, 255, 255, 255);
        SDL_RenderClear(state.renderer);

        SDL_FRect sprite {
            .x = 0,
            .y = 0,
            .w = 21,
            .h = 31
        };

        SDL_FRect drawSprite {
            .x = (float)width/2,
            .y = (float)height/2,
            .w = 21,
            .h = 31
        };

        SDL_RenderTexture(state.renderer, idle_texture, &sprite, &drawSprite);

        SDL_RenderPresent(state.renderer);
         
    }

    SDL_DestroyTexture(idle_texture);
    cleanup();
    return 0;
}

void cleanup(){
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.windows);
    SDL_Quit();
}