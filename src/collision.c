#include "../inc/header.h"

void collision(GameState *game) { // неможливість зіткнення з будь-яким блоком
    float mw, mh;
    float mx, my;
    float bx, by, bw, bh;
    
    for(int i = 0; i < 100; i++) {
        mw = 58, mh = 48;
        mx = game->man.x, my = game->man.y;
        bx = game->ledges[i].x, by = game->ledges[i].y, bw = game->ledges[i].w,
        bh = game->ledges[i].h;
        if (mx + mw / 2 > bx && mx + mw / 2 < bx + bw) { // тверда платформа знизу
            if (my < by+bh && my > by && game->man.dy < 0) {
                game->man.y = by+bh;
                my = by+bh;
                game->man.dy = 0;
                game->man.onLedge = 1;
            }
        }
        if (mx+mw > bx && mx<bx+bw) {
            if (my+mh > by && my < by && game->man.dy > 0) { // приземлення на платформу
                game->man.y = by-mh;
                my = by-mh;
                game->man.dy = 0;
                game->man.onLedge = 1;
            }
        }
        if (my+mh > by && my<by+bh) { // тверда платформа збоку
            if (mx < bx+bw && mx+mw > bx+bw && game->man.dx < 0) {
                game->man.x = bx+bw;
                mx = bx+bw;
                game->man.dx = 0;
            }
            else if (mx+mw > bx && mx < bx && game->man.dx > 0) {
                game->man.x = bx-mw;
                mx = bx-mw;
                game->man.dx = 0;
            }
        }
    }
}
