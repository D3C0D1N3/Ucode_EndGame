#include "../inc/header.h"

void process(SDL_Window *window, GameState *game) {
    game->time++;
  
    if(game->statusState == STATUS_STATE_LIVES) {
        if(game->time > 120) {
            game->statusState = STATUS_STATE_GAME;
            Mix_PlayMusic(game->bgMusic, -1);
            //game->musicChannel = Mix_PlayChannel(-1, game->bgMusic, -1);
        }
    }
    else if(game->statusState == STATUS_STATE_GAMEOVER) {
        if(game->time > 190) {
        load_game(game);
        menu(window, game->renderer);
        }
    }
    else if(game->statusState == STATUS_STATE_GAME) {
        if(!game->man.isDead) {
            Man *man = &game->man;
            man->x += man->dx;
            man->y += man->dy;
            if(man->dx != 0 && man->onLedge && !man->slowingDown) {
                if(game->time % 8 == 0) {
                    if(man->animFrame == 0)
                        man->animFrame = 1;
                    else
                        man->animFrame = 0;
                }
            }
            // if(man->x > 38320) { // на випадок якщо буде кінець левела
            //     init_game_win(game);
            //     game->statusState = STATUS_STATE_WIN;
            // }
            man->dy += GRAVITY;
            for(int i = 0; i < NUM_STARS; i++) { // рух перешкод
                game->stars[i].x = game->stars[i].baseX;
                game->stars[i].y = game->stars[i].baseY;          
                if(game->stars[i].mode == 0)
                    game->stars[i].x = game->stars[i].baseX + sinf(game->stars[i].phase+game->time * 0.06f) * 75;
                else
                    game->stars[i].y = game->stars[i].baseY + cosf(game->stars[i].phase+game->time * 0.06f) * 75;
            }
        }
        if(game->man.isDead && game->deathCountdown < 0)
           game->deathCountdown = 120;
        if(game->deathCountdown >= 0) {
            game->deathCountdown--;
            if(game->deathCountdown < 0) {
                game->man.lives--;
              
                if(game->man.lives >= 0) {
                    game->statusState = STATUS_STATE_LIVES;
                    game->time = 0;
                    //reset
                    game->man.isDead = 0;
                    game->man.x = 100;
                    game->man.y = 240-40;
                    game->man.dx = 0;
                    game->man.dy = 0;
                    game->man.onLedge = 0;
                    init_stars(game);
                }
                else {
                    init_game_over(game);
                    game->statusState = STATUS_STATE_GAMEOVER;
                    game->time = 0;
                }
            }
        }
    }
    
    game->scrollX = -game->man.x + 700 / 2;
    if(game->scrollX > 1000) //скрол вліво на початку екрану
        game->scrollX = 1000;
    if(game->scrollX < -38000 + 320 / 2)
        game->scrollX = -38000 + 320 / 2;
}

