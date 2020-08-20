#include "../inc/header.h"

void event(SDL_Window *win, SDL_Renderer *rend) {
    bool game = true;
    SDL_Event event;

    SDL_Surface *surf = IMG_Load("../assets/back.jpg");
    SDL_Texture *text = SDL_CreateTextureFromSurface(rend, surf);
    SDL_FreeSurface(surf);
    SDL_Rect *dest;
    SDL_QueryTexture(text, NULL, NULL, &dest->w, &dest->h);

    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, text, NULL, &dest);
    SDL_RenderPresent(rend);
    SDL_Delay(3000);
    
    while(game) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    exit(0);
                case SDL_KEYDOWN:
                    switch(event.key.keysym.scancode) {
                        case SDLK_ESCAPE:
                            exit(0);
                    }
            }
        }
    }
}