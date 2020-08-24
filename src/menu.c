#include "header.h"

#undef main

int menu(SDL_Window *window, SDL_Renderer *renderer) {
    static const char *bgMenu = "resource/sounds/background.ogg";
    static const char *click = "resource/sounds/click.wav";

    bool quit = false; 
    SDL_Event input;
    //SDL_Window* window = NULL;
    
    SDL_Texture* texture;
    SDL_Texture* texture_coparete;
    SDL_Texture* texture_legends;
    SDL_Texture* texture_legends2;
    SDL_Texture* texture_start;
    SDL_Texture* texture_start2;
    SDL_Texture* texture_quit;
    SDL_Texture* texture_quit2;
    
    SDL_Surface *button_quit;
    SDL_Surface *button_quit2;
    SDL_Surface *temp;
    SDL_Surface *coparete;
    SDL_Surface *button_legends;
    SDL_Surface *button_legends2;
    SDL_Surface *button_start;
    SDL_Surface *button_start2;
    
    SDL_Rect rect;
    SDL_Rect rect2;
    SDL_Rect rect3;
    SDL_Rect rect4;
    SDL_Rect rect5;
    SDL_Rect rect6;
    SDL_Rect rect7;
    SDL_Rect rect8;

    texture = NULL;
    texture_coparete = NULL;
    
    texture_legends = NULL;
    texture_legends2 = NULL;
    
    texture_start = NULL;
    texture_start2 = NULL;
    
    texture_quit = NULL;
    texture_quit2 = NULL;
    //----------------------
    temp = IMG_Load("resource/images/menu/backend.jpg");
    coparete = IMG_Load("resource/images/menu/image-22.png");
    
    button_legends = IMG_Load("resource/images/menu/image-21.png");
    button_legends2 = IMG_Load("resource/images/menu/image-21.png");
    
    button_start = IMG_Load("resource/images/menu/image-16.png");
    button_quit = IMG_Load("resource/images/menu/image-3.png");
    
    button_quit2 = IMG_Load("resource/images/menu/image-3.png");
    button_start2 = IMG_Load("resource/images/menu/image-16.png");

    //Filling texture with the image using a surface
    texture = SDL_CreateTextureFromSurface(renderer, temp);
    texture_coparete = SDL_CreateTextureFromSurface(renderer, coparete);
    texture_legends = SDL_CreateTextureFromSurface(renderer, button_legends);
    texture_legends2 = SDL_CreateTextureFromSurface(renderer, button_legends2);
    texture_start = SDL_CreateTextureFromSurface(renderer, button_start);
    texture_start2 = SDL_CreateTextureFromSurface(renderer, button_start2);
    texture_quit = SDL_CreateTextureFromSurface(renderer, button_quit);
    texture_quit2 = SDL_CreateTextureFromSurface(renderer, button_quit2);

    //Deleting the temporary surface
    SDL_FreeSurface(temp);

    rect.x = 0; //Extreme left of the window
    rect.y = 0; //Very bottom of the window
    rect.w = 1280; //100 pixels width
    rect.h = 720; //100 pixels height
    //'rect' defines the dimensions for the bottom-left of the window

    
    SDL_FreeSurface(button_start);

    rect2.x = 555; //Extreme left of the window
    rect2.y = 218; //Very bottom of the window
    rect2.w = 150; //100 pixels width
    rect2.h = 48; //100 pixels height 

    SDL_FreeSurface(button_start2);

    rect4.x = 550; //Extreme left of the window
    rect4.y = 215; //Very bottom of the window
    rect4.w = 155; //100 pixels width
    rect4.h = 51; //100 pixels height   

    SDL_FreeSurface(button_quit);

    rect3.x = 480; //Extreme left of the window
    rect3.y = 350; //Very bottom of the window
    rect3.w = 300; //100 pixels width
    rect3.h = 100; //100 pixels height  

    SDL_FreeSurface(button_quit2);

    rect5.x = 455; //Extreme left of the window
    rect5.y = 347; //Very bottom of the window
    rect5.w = 355; //100 pixels width
    rect5.h = 103; //100 pixels height  

    SDL_FreeSurface(button_legends);

    rect6.x = 530; //Extreme left of the window
    rect6.y = 290; //Very bottom of the window
    rect6.w = 200; //100 pixels width
    rect6.h = 50; //100 pixels height  

    SDL_FreeSurface(button_legends2);

    rect7.x = 530; //Extreme left of the window
    rect7.y = 290; //Very bottom of the window
    rect7.w = 210; //100 pixels width
    rect7.h = 55; //100 pixels height  

    SDL_FreeSurface(coparete);

    rect8.x = 1050; //Extreme left of the window
    rect8.y = 670; //Very bottom of the window
    rect8.w = 200; //100 pixels width
    rect8.h = 50; //100 pixels height  

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
    Mix_Music *sound = Mix_LoadMUS(bgMenu);
    Mix_Chunk *clicks = Mix_LoadWAV(click);
    if (sound != NULL) {
        Mix_VolumeMusic(100);
    }
    if (clicks != NULL) {
        Mix_VolumeChunk(clicks, 50);
    }
    Mix_PlayMusic(sound, -1);

    while (!quit)
    {
        int x;
        int y;

        x = input.motion.x;
        y = input.motion.y;

        while (SDL_PollEvent(&input) > 0) {
            if (input.type == SDL_QUIT) {
                Mix_PlayChannel(2, clicks, 0);
                quit = true;
            }
        }

        if(input.type == SDL_MOUSEBUTTONDOWN) {
            if(input.button.button == SDL_BUTTON_LEFT 
                && input.button.x >= 560 && input.button.x <= 695
                && input.button.y >= 225 && input.button.y <= 260)  {
                Mix_HaltMusic();
                Mix_PlayChannel(2, clicks, 0);
                return 1;
            }
        }
        if(input.type == SDL_MOUSEBUTTONDOWN) {
            if(input.button.button == SDL_BUTTON_LEFT 
                && input.button.x >= 525 && input.button.x <= 700
                && input.button.y >= 290 && input.button.y <= 340) {
                Mix_PlayChannel(2, clicks, 0);
                quit = false;
            }
        }
        if(input.type == SDL_MOUSEBUTTONDOWN) {
             if(input.button.button == SDL_BUTTON_LEFT 
                && input.button.x >= 580 && input.button.x <= 680
                && input.button.y >= 375 && input.button.y <= 410) {
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

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //Copying the texture on to the window using renderer and rectangle
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_RenderCopy(renderer, texture_coparete, NULL, &rect8);
        if ((y >= 225 && y <= 260) && (x >= 560 && x <= 695)) {
            SDL_RenderCopy(renderer, texture_quit, NULL, &rect3);
            SDL_RenderCopy(renderer, texture_start2, NULL, &rect4);
            SDL_RenderCopy(renderer, texture_legends, NULL, &rect6);
            SDL_RenderPresent(renderer);
        }
        else if((y >= 375 && y <= 410) && (x >= 580 && x <= 680)) {
            SDL_RenderCopy (renderer, texture_start, NULL, &rect2);
            SDL_RenderCopy(renderer, texture_quit2, NULL, &rect5);
            SDL_RenderCopy(renderer, texture_legends, NULL, &rect6);
            SDL_RenderPresent(renderer);
        }
        else if((x >= 525 && x <= 700) && (y >= 290 && y <= 340)) {
            SDL_RenderCopy (renderer, texture_start, NULL, &rect2);
            SDL_RenderCopy(renderer, texture_quit, NULL, &rect3);
            SDL_RenderCopy(renderer, texture_legends2, NULL, &rect7);
            SDL_RenderPresent(renderer);
        }
        else {
            SDL_RenderCopy(renderer, texture_quit, NULL, &rect3);
            SDL_RenderCopy(renderer, texture_legends, NULL, &rect6);
            SDL_RenderCopy (renderer, texture_start, NULL, &rect2);
            SDL_RenderPresent(renderer);
        }
    }

    //Deleting the texture
    SDL_DestroyTexture(texture_start);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    //For quitting IMG systems
    IMG_Quit();
    Mix_FreeMusic(sound);
    Mix_FreeChunk(clicks);
    Mix_CloseAudio();

    SDL_Quit();

    
    exit(0);
    system("leaks -q endgame");
}
