#include "../inc/header.h"

int main(int argc, char *argv[]) {
    GameState gameState;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    srandom((int)time(NULL));

    window = SDL_CreateWindow(&argv[0][2], //створюємо вікно
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              WINDOW_H,
                              WINDOW_W,
                              0
                              );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED 
                                  | SDL_RENDERER_PRESENTVSYNC);
    gameState.renderer = renderer;

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096); //initialize sound

    menu(window, renderer);

    load_game(&gameState);

    int done = 0;

    while(!done) {
        done = process_events(window, &gameState); // процес гри

        process(window, &gameState);
        collision_detect(&gameState);

        do_render(renderer, &gameState);
    }
    // звільняємо память
    SDL_DestroyTexture(gameState.star);
    SDL_DestroyTexture(gameState.manFrames[0]);
    SDL_DestroyTexture(gameState.manFrames[1]);
    SDL_DestroyTexture(gameState.brick);

    Mix_FreeMusic(gameState.bgMusic);
    Mix_FreeChunk(gameState.dieSound);
    Mix_FreeChunk(gameState.jumpSound);
    Mix_FreeChunk(gameState.landSound);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
    argc = 0;
    // system("leaks -q game");
    return 0;
}
