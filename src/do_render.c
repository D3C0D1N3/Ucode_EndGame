#include "../inc/header.h"

void do_render(SDL_Renderer *renderer, GameState *game) {

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, game->back, NULL, NULL);

    for (int i = 0; i < 100; i++) { // Малюємо платформу
        SDL_Rect ledgeRect = {game->ledges[i].x, game->ledges[i].y, game->ledges[i].w, game->ledges[i].h };
        SDL_RenderCopy(renderer, game->brick, NULL, &ledgeRect);
    }
    
    SDL_Rect rect = {game->man.x, game->man.y, 48, 48};
    SDL_RenderCopyEx(renderer, game->manFrames[game->man.animFrame], 
                     NULL, &rect, 0, NULL, (game->man.facingLeft == 0));

    // for (int i = 0; i < 100; i++) { // Малюємо перешкоди
    //     SDL_Rect starRect = { game->stars[i].x, game->stars[i].y, 64, 64 };
    //     SDL_RenderCopy(renderer, game->star, NULL, &starRect);
    // }
    SDL_RenderPresent(renderer);
}
