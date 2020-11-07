#include "header.h"

e_game main_process (SDL_Window *window, GameState *game) {
    game->status = GAME_STATE;

    int done = 0;

    while(!done) {
        do_render(game);

        collision_detect(game);

        done = process_events(window, game); // процес гри

        done = process(game);

        done = game->copydone;
        destroy_game(game);
        int a[] = [EXIT_STATE, MENU_STATE, GAMEOVER_STATE];
        return a[done - 1];
    }
    return GAME_STATE;
}
