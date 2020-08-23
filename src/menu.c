#include "../inc/header.h"

#undef main

int menu(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);

    bool quit = false; 
    SDL_Event input;
    SDL_Texture* texture;
    SDL_Texture* texture_start;
    SDL_Texture* texture_quit;
    SDL_Surface* button_quit;
    SDL_Surface* temp;
    SDL_Rect rect;
    SDL_Surface *button_start;
    SDL_Rect rect2;
    SDL_Rect rect3;
    
    texture = NULL;
    texture_start = NULL;
    texture_quit = NULL;

    temp = IMG_Load("/Users/ymrozek/Desktop/EndGameCollab/assets/menu/backend.jpg");
    button_start = IMG_Load("/Users/ymrozek/Desktop/EndGameCollab/assets/menu/image-4.png");
    button_quit = IMG_Load("/Users/ymrozek/Desktop/EndGameCollab/assets/menu/image-3.png");

    //Filling texture with the image using a surface
    texture = SDL_CreateTextureFromSurface(renderer, temp);
    texture_start = SDL_CreateTextureFromSurface(renderer, button_start);
    texture_quit = SDL_CreateTextureFromSurface(renderer, button_quit);

    //Deleting the temporary surface
    SDL_FreeSurface(temp);

    rect.x = 0; //Extreme left of the window
    rect.y = 0; //Very bottom of the window
    rect.w = 1280; //100 pixels width
    rect.h = 720; //100 pixels height
    //'rect' defines the dimensions for the bottom-left of the window

    SDL_FreeSurface(button_start);

    rect2.x = 480; //Extreme left of the window
    rect2.y = 200; //Very bottom of the window
    rect2.w = 300; //100 pixels width
    rect2.h = 100; //100 pixels height   

    SDL_FreeSurface(button_quit);

    rect3.x = 480; //Extreme left of the window
    rect3.y = 350; //Very bottom of the window
    rect3.w = 300; //100 pixels width
    rect3.h = 100; //100 pixels height  

    while (!quit)
    {
        while (SDL_PollEvent(&input) > 0) {
            if (input.type == SDL_QUIT) 
            quit = true;
        }
        
        if(input.type == SDL_MOUSEBUTTONDOWN) {
            if(input.button.button == SDL_BUTTON_LEFT 
                && input.button.x >= 480 && input.button.x <= 780
                && input.button.y >= 200 && input.button.y <= 300) {
                return 0;
            }
        }
        if(input.type == SDL_MOUSEBUTTONDOWN) {
             if(input.button.button == SDL_BUTTON_LEFT 
                && input.button.x >= 480 && input.button.x <= 780
                && input.button.y >= 350 && input.button.y <= 450) {
                quit = true;
            }
        }
        if(input.type == SDL_KEYDOWN) {
            switch(input.key.keysym.sym) {
                case SDLK_ESCAPE:
                    quit = true;
                break;
            }
        }
    
        
        SDL_RenderClear(renderer);

        //Copying the texture on to the window using renderer and rectangle
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_RenderCopy(renderer, texture_start, NULL, &rect2);
        SDL_RenderCopy(renderer, texture_quit, NULL, &rect3);

        SDL_RenderPresent(renderer);
    }
    //Deleting the texture
    SDL_DestroyTexture(texture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    //For quitting IMG systems
    IMG_Quit();

    SDL_Quit();

    exit(1);
}
