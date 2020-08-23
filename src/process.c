#include "../inc/header.h"

void process(GameState *game) {
    game->time++;

    Man *man = &game->man;
    man->x += man->dx;
    man->y += man->dy;

    if(man->dx != 0 && man->onLedge /*&& !man->slowingDown*/) {
        if(game->time % 8 == 0) {
            if(man->animFrame == 0)
                man->animFrame = 1;
            else
                man->animFrame = 0;
        }
    }
    man->dy += 0.362f;
}
