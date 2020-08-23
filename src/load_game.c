#include "../inc/header.h"

void load_game(GameState *game) { // Переганяємо зображення
    SDL_Surface *surface = NULL;

    surface = IMG_Load("/Users/ymrozek/Desktop/EndGameCollab/assets/level/back.png");
    if (!surface) {
        printf("back error\n");
        exit(2);
    }
    game->back = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("/Users/ymrozek/Desktop/EndGameCollab/assets/hero/hero.png");
    if(!surface) {
        printf("hero error\n");
        exit(2);
    }    
    game->manFrames[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("/Users/ymrozek/Desktop/EndGameCollab/assets/hero/hero2.png");
    if(!surface) {
        printf("hero error\n");
        exit(2);
    }    
    game->manFrames[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("/Users/ymrozek/Desktop/EndGameCollab/assets/level/purple_plat.png");
    if(!surface) {
        printf("purple_plat error\n");
        exit(2);
    }
    game->brick = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    game->man.x = 0; // стартові координати
    game->man.y = 240 - 40;
    game->man.dy = 0;
    game->man.onLedge = 0;
    game->man.animFrame = 0;
    game->man.facingLeft = 1;
   /* game->man.slowingDown = 0;*/
    game->time = 0;

    for (int i = 0; i < 100; i++) {
        game->stars[i].x = random() % 1280;
        game->stars[i].y = random() % 720;
    }

    for (int i = 0; i < 100; i++) { // Нижня платформа
        game->ledges[i].w = 256; // довжина 256
        game->ledges[i].h = 64; // висота 64
        game->ledges[i].x = i * 256; // створюємо наступні платформи
        game->ledges[i].y = (480-64-5); // розміщення (розмір екрану - розмір платформи - пустота знизу)
    }
    game->ledges[99].x = 350; // Верхня платформа
    game->ledges[99].y = 200;

    game->ledges[98].x = 10; // Верхня платформа
    game->ledges[98].y = 100;
}
