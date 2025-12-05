#ifndef GAME_HPP
#define GAME_HPP

    #include <SDL3/SDL.h>
    #include <SDL3/SDL_main.h>

    class trauma_state{
        public:
            SDL_Window *windows;
            SDL_Renderer *renderer;
            int WINDOW_WIDTH;
            int WINDOW_HEIGHT;
            int WINDOW_LOGICAL_WIDTH;
            int WINDOW_LOGICAL_HEIGHT;

        trauma_state(SDL_Window *windows, SDL_Renderer *renderer){
            this->windows = windows;
            this->renderer = renderer;
            this->WINDOW_WIDTH = 1600;
            this->WINDOW_HEIGHT = 900;
            this->WINDOW_LOGICAL_WIDTH = 640;
            this->WINDOW_LOGICAL_HEIGHT = 320;
        }
    };

    bool initialise(trauma_state &state);
    void cleanup(trauma_state &state);


#endif