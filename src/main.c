#include "../inc/header.h"

int main() {
    init_sdl();
    
    SDL_Window *window{ nullptr }
    SDL_Surface *screenSurface{ nullptr }

    window = SDL_CreateWindow ( "GAME WINDOW",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_OPENGL );
}
