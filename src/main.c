#include "../inc/header.h"

int main() {
    GameState game;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    // srandom((int)time(NULL));

    window = SDL_CreateWindow("Topovo",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              1280, 720, 0);   //створюємо вікно

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED 
                                  | SDL_RENDERER_PRESENTVSYNC);
    game.renderer = renderer;
    load_game(&game);
    //menu(window, renderer);
    int done = 0;

    done = menu(window, renderer);
    
    while(!done) {
        processEvents(window, &game);
        process(&game);
        collision(&game);
        do_render(renderer, &game);
    }
    //звільняємо память
    //SDL_DestroyTexture(game.star);
    SDL_DestroyTexture(game.manFrames[0]);
    SDL_DestroyTexture(game.brick);
    SDL_DestroyTexture(game.back);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    system("leaks -q game");
    return 0;
}
