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
    //creating window
    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error initializing SDL3", nullptr);
        return 1;
    }

    int width = 800;
    int height = 600;

    state.windows = SDL_CreateWindow("SDL3 demo", width, height, 0);
    if(state.windows == NULL){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating SDL3 window", nullptr);
        SDL_Quit();
        return 1;
    }

    state.renderer = SDL_CreateRenderer(state.windows, NULL);
    if(state.renderer == NULL){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating render for window", nullptr);
        cleanup();
        return 1;
    }

    SDL_RenderPresent(state.renderer);

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
            }
        }

        //update


        //render
        SDL_SetRenderDrawColor(state.renderer, 255, 255, 255, 255);
        SDL_RenderClear(state.renderer);

        SDL_RenderPresent(state.renderer);
        
    }

    

    
    

    cleanup();
    return 0;
}

void cleanup(){
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.windows);
    SDL_Quit();
}