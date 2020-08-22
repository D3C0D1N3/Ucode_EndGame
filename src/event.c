#include "../inc/header.h"

void render_update(SDL_Renderer *rend, SDL_Texture *text[], SDL_Rect *destrect[], int states[]) {
    SDL_RenderClear(rend);
    if (states[0]) SDL_RenderCopy(rend, text[0], NULL, destrect[0]);
    if (states[1]) SDL_RenderCopy(rend, text[1], NULL, destrect[1]);
}

int event(SDL_Window *win, SDL_Renderer *rend) {
    bool game = true;
    float x_vel = 1.2;
    float y_vel = 1;

    SDL_DisplayMode display;
                    display.w = 480;
                    display.h = 360;
    SDL_Rect hero_rect;
                  hero_rect.x = 100;
                  hero_rect.y = 250;
                  hero_rect.h = 58;
                  hero_rect.w = 40;
    SDL_Rect back_rect;
                  back_rect.x = 0;
                  back_rect.y = 0;
                  back_rect.w = display.w;
                  back_rect.h = display.h;
    SDL_Texture *hero_tex = IMG_LoadTexture(rend, "/Users/ymrozek/Desktop/EndGameCollab/assets/hero/hero.png");
    SDL_Texture *back_tex = IMG_LoadTexture(rend, "/Users/ymrozek/Desktop/EndGameCollab/assets/level/images.jpg");
    //SDL_Texture *hero_tex = IMG_LoadTexture(rend, "/root/Desktop/EndGameCollab/assets/hero/hero.png");
    //SDL_Texture *back_tex = IMG_LoadTexture(rend, "/root/Desktop/EndGameCollab/assets/level/images.jpg");

    SDL_Texture *ARRAY_Textures[2] = {back_tex, hero_tex};
    SDL_Rect *ARRAY_Rect[2] = {&back_rect, &hero_rect};
    int ARRAY_texturesState[2] = {1, 1};
    SDL_Event event;
    //EVENT LOOOOOOP
    while(game) {
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game = false;
            }
        }
        const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
            if (keyboardState[SDL_SCANCODE_W]) {
                hero_rect.y -= y_vel;
                SDL_RenderClear(rend);
                SDL_RenderCopy(rend, hero_tex, NULL, &hero_rect);
            }
            if (keyboardState[SDL_SCANCODE_S]) {
                hero_rect.y += y_vel;
                SDL_RenderClear(rend);
                SDL_RenderCopy(rend, hero_tex, NULL, &hero_rect);
            }
            if (keyboardState[SDL_SCANCODE_A]) {
                hero_rect.x -= x_vel;
                SDL_RenderClear(rend);
                SDL_RenderCopy(rend, hero_tex, NULL, &hero_rect);
            }
            if (keyboardState[SDL_SCANCODE_D]) {
                hero_rect.x += x_vel * 2;
                SDL_RenderClear(rend);
                SDL_RenderCopy(rend, hero_tex, NULL, &hero_rect);
            }
        render_update(rend, ARRAY_Textures, ARRAY_Rect, ARRAY_texturesState);
        SDL_RenderPresent(rend);
        if (hero_rect.x <= 0) hero_rect.x += 2;
        if (hero_rect.x >= 440) hero_rect.x -= 2;
        if (hero_rect.y <= 240) hero_rect.y += 2;
        if (hero_rect.y >= 260) hero_rect.y -= 2;
    }

    SDL_RenderClear(rend);
    SDL_DestroyTexture(hero_tex);
    SDL_DestroyTexture(back_tex);
    return 2;
}
