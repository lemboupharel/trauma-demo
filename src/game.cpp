#include "../include/game.hpp"

bool initialise(trauma_state &state){
        //initialize SDL3
    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error initializing SDL3", nullptr);
        return false;
    }


    //creating window
    state.windows = SDL_CreateWindow("SDL3 demo", state.WINDOW_WIDTH, state.WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
    if(state.windows == NULL){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating SDL3 window", nullptr);
        SDL_Quit();
        return false;
    }


    //creating render
    state.renderer = SDL_CreateRenderer(state.windows, NULL);
    if(state.renderer == NULL){
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Error creating render for window", nullptr);
        cleanup(state);
        return false;
    }

    // configure presentation
    if(!SDL_SetRenderLogicalPresentation(state.renderer, state.WINDOW_LOGICAL_WIDTH, state.WINDOW_LOGICAL_HEIGHT, SDL_LOGICAL_PRESENTATION_LETTERBOX)) return false;
    
    return true;
}


void cleanup(trauma_state &state){
    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.windows);
    SDL_Quit();
}