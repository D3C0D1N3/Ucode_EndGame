#pragma once

//наши фреймворки (Тут будут закомичены хедеры и левые фреймворки)
//Все что в include/SDL... для линукса на дому.
#include "../macFrameworks/SDL2.framework/Headers/SDL.h"
#include "../macFrameworks/SDL2_image.framework/Headers/SDL_image.h"
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL2_gfxPrimitives.h>

//Подключение хэдеров


//системные библиотеки
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

typedef struct // Герой
{
    float x, y;
    float dx, dy;
    short life;
    char *name;
    int onLedge;

    int animFrame, facingLeft/*, slowingDown*/;
} Man;

typedef struct // Перешкоди
{
    int x, y;
} Star;

typedef struct { // Платформи
    int x, y, w, h;
}   Ledge;

typedef struct  // Безпосередньо структура гри
{
    Man man;

    Star stars[100];

    Ledge ledges[100];

    SDL_Texture *star;
    SDL_Texture *manFrames[2];
    SDL_Texture *brick;
    SDL_Texture *back;

    SDL_Renderer *renderer;

    int time;
} GameState;

//декларация функций
void init_sdl();
void collision(GameState *game);
int menu(SDL_Window *window, SDL_Renderer *renderer);
void load_game(GameState *game);
void process(GameState *game);
bool processEvents(SDL_Window *window, GameState *game);
void do_render(SDL_Renderer *renderer, GameState *game);
