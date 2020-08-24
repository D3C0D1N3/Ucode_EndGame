#include "../inc/header.h"

void do_render(SDL_Renderer *renderer, GameState *game) {

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, game->level_back, NULL, NULL);

    for (int i = 0; i < NUM_LEDGES; i++) { // Малюємо платформу
        SDL_Rect ledgeRect = {game->scrollX + game->ledges[i].x, game->ledges[i].y, game->ledges[i].w, game->ledges[i].h };
        SDL_RenderCopy(renderer, game->brick, NULL, &ledgeRect);
    }
    
    for (int i = 0; i < NUM_STARS; i++) { // Малюємо перешкоди
        SDL_Rect starRect = { game->scrollX + game->stars[i].x, game->stars[i].y, 64, 64 };
        SDL_RenderCopy(renderer, game->star, NULL, &starRect);
    }

    SDL_Rect rect = {game->scrollX + game->man.x, game->man.y, 48, 48}; // Малюємо персонажа
    SDL_RenderCopyEx(renderer, game->manFrames[game->man.animFrame], 
                     NULL, &rect, 0, NULL, (game->man.facingLeft == 0));
    
    if(game->man.isDead) { // смерть персонажа
        SDL_Rect rect = { game->scrollX+game->man.x-24+38/2+10, game->man.y-24-83/2, 38, 83 };
        SDL_RenderCopyEx(renderer, game->fire,
                         NULL, &rect, 0, NULL, (game->time % 20 < 10));
    }
    SDL_RenderPresent(renderer);
}
