#pragma once

//наши фреймворки
#include "../frameworks/SDL2.framework/Headers/SDL.h"
#include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"

//Подключение хэдеров


//системные библиотеки
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>



//декларация функций
void init_sdl();
void event(SDL_Window *win, SDL_Renderer *rend);
