#include "../inc/header.h"

void init_sdl() {
    if ((SDL_INIT_EVERYTHING) == 0) {
        printf("Error init sdl: %s \n", SDL_GetError());
        SDL_Quit();
        exit(0);
    }
    SDL_Window *win = SDL_CreateWindow("FUCKING GAMMEE",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       1280, 1080, 0);
    if(!win)
        printf("Error creating window: %s \n", SDL_GetError());
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);
    if (!rend)
        printf("Error creating renderer: %s \n", SDL_GetError());
    event(win, rend);
}
