#pragma once

#define GRAVITY 0.362f
#define STATUS_STATE_LIVES 0
#define STATUS_STATE_GAME 1
#define STATUS_STATE_GAMEOVER 2
#define STATUS_STATE_WIN 3

#define NUM_STARS 100
#define NUM_LEDGES 120

#define WINDOW_H 1280  // 1280 - 640
#define WINDOW_W 720 // 720 - 480

//наши фреймворки
#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

//системные библиотеки
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

//декларация функций

typedef struct // Персонаж / MAn
{
    float x, y;
    float dx, dy;
    short lives;
    char *name;
    int onLedge, isDead;
    int animFrame, facingLeft, slowingDown;
} Man;

typedef struct // Перешкоди / Star
{
    int x, y, baseX, baseY, mode;
    float phase;
} Star;

typedef struct { // Платформи / Ledge
    int x, y, w, h;
}   Ledge;

typedef struct  // Безпосередньо структура гри / GameState
{
    float scrollX;
    Man man;
    Star stars[NUM_STARS];
    Ledge ledges[NUM_LEDGES];
    //картинки
    SDL_Texture *star;
    SDL_Texture *manFrames[2];
    SDL_Texture *brick;
    SDL_Texture *fire;
    SDL_Texture *level_back;
    //шрифт
    int time, deathCountdown;
    int statusState;
    //звук
    int musicChannel;
    Mix_Music *bgMusic;
    Mix_Chunk *jumpSound, *landSound, *dieSound;

    SDL_Renderer *renderer;
} GameState;

void init_sdl();
void print_error(SDL_Surface *surface, char *s);
void init_game_over(GameState *game);
void init_stars(GameState *game);
void load_game(GameState *game);
void process(SDL_Window *window, GameState *game);
void collision_detect(GameState *game);
int process_events(SDL_Window *window, GameState *game);
void do_render(SDL_Renderer *renderer, GameState *game);
int menu(SDL_Window *window, SDL_Renderer *renderer);
