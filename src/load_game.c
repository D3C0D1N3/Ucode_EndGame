#include "../inc/header.h"

void load_game(GameState *game) { // Переганяємо зображення
    SDL_Surface *surface = NULL;

    // static const char *background = "resource/sounds/background.ogg"
    // static const char *jumpSound = "resource/sounds/JumpEffect.wav"
    // static const char *dieSound = "resource/sounds/button.wav"
    // static const char *landSound = "resource/sounds/land.wav"
    
    surface = IMG_Load("resource/images/level/fon.jpg");
    print_error(surface, "Some problems with level back");
    game->level_back = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("resource/images/level/star.png");
    print_error(surface, "Some problems with obstacles");
    game->star = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("resource/images/hero/walk_1.png");
    print_error(surface, "Some problems with hero");
    game->manFrames[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("resource/images/hero/walk_2.png");
    print_error(surface, "Some problems with hero");
    game->manFrames[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("resource/images/hero/fire.png");
    print_error(surface, "Some problems with fire");
    game->fire = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("resource/images/level/blocks.png");
    print_error(surface, "Some problems with blocks");
    game->brick = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);


    //Завантажуємо музику
    game->bgMusic = Mix_LoadMUS("resource/sounds/gameback.ogg");

    if(game->bgMusic != NULL) {
    Mix_VolumeMusic(70);
    }

    game->dieSound = Mix_LoadWAV("resource/sounds/button.wav");
    game->jumpSound = Mix_LoadWAV("resource/sounds/JumpEffect.wav");
    game->landSound = Mix_LoadWAV("resource/sounds/land.wav");
    
       // if(game->dieSound != NULL || game->jumpSound != NULL 
         // || game->landSound!= NULL) {
            Mix_VolumeChunk(game->dieSound, 45);
            Mix_VolumeChunk(game->jumpSound, 20);
            Mix_VolumeChunk(game->landSound, 45);

   // }

    game->man.x = 50; // стартові координати
    game->man.y = 480 / 2 - 40;
    game->man.dx = 0;
    game->man.dy = 0;
    game->man.onLedge = 0;
    game->man.animFrame = 0;
    game->man.facingLeft = 1;
    game->man.slowingDown = 0;
    game->man.lives = 0;
    game->man.isDead = 0;
    game->statusState = STATUS_STATE_LIVES;
    game->time = 0;
    game->scrollX = 0;
    game->deathCountdown = -1;

    init_stars(game);

    for(int i = 0; i < NUM_LEDGES /*- 20*/; i++) {
        game->ledges[i].w = 256 - random() % 50; // довжина 256
        game->ledges[i].h = 64; // висота 64
        game->ledges[i].x = i * 480; // створюємо наступні платформи
        if(i == 0)
            game->ledges[i].y = (600 - 64 - 5); // розміщення (розмір екрану - розмір платформи - пустота знизу)
        else
            game->ledges[i].y = 500 + 100 - random() % 200;
    }

    // for(int i = (NUM_LEDGES - 20); i < NUM_LEDGES; i++) { // треба правити!!!
    //     game->ledges[i].w = 256; // довжина 256
    //     game->ledges[i].h = 64;
    //     game->ledges[i].x = 350 + random() % 38400;
    //     if (i % 2 == 0)
    //         game->ledges[i].y = 200;
    //     else
    //         game->ledges[i].y = 350;
    // }
}
