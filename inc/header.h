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

//декларация функций
void init_sdl();
int event(SDL_Window *win, SDL_Renderer *rend);
int menu(SDL_Window *win, SDL_Renderer *rend);
