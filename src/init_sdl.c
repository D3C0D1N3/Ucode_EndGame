#include "../inc/header.h"

void init_sdl() {
    if ((SDL_INIT_EVERYTHING) != 0) {
        printf("Error init sdl: %s \n", SDL_GetError());
        SDL_Quit();
        exit(0);
    }
    printf("Successfuly init sdl\n");
}
