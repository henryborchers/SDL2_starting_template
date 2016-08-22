//
// Created by Borchers, Henry Samuel on 8/20/16.
//


#include <stdio.h>

#include "sdlstuff.h"

const int MY_WINDOW_WIDTH = 640;
const int MY_WINDOW_HEIGHT = 480;
const int MY_TEXTURE_HEIGHT = 100;
const int MY_TEXTURE_WIDTH = 100;


int say_hi() {
    puts("Hi");
    return 0;
}

int basicSDL2() {
    SDLContext ctx;


    if(basicSDL2init(&ctx) < 0){
        fprintf(stderr, "Unable to initialize SDL2\n");
    };

    basicSDL2mainLoop(&ctx);

    basicSDL2cleanup(&ctx);
    return 0;

}

int basicSDL2init(SDLContext *ctx) {
    ctx->window = NULL;
    ctx->renderer = NULL;
    ctx->texture = NULL;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return -1;
    };

    ctx->window = SDL_CreateWindow("My Window", 100, 100, MY_WINDOW_WIDTH, MY_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(ctx->window == NULL) {
        fprintf(stderr, "SDL_CreateWindow error %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    ctx->renderer = SDL_CreateRenderer(ctx->window, -1, SDL_RENDERER_ACCELERATED);
    if(ctx->renderer == NULL){
        fprintf(stderr, "SDL_CreateRenderer error %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }


    ctx->texture = SDL_CreateTexture(ctx->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, MY_TEXTURE_HEIGHT, MY_TEXTURE_WIDTH);
    if(ctx->texture == NULL){
        fprintf(stderr, "SDL_CreateTexture error %s\n", SDL_GetError());
        SDL_Quit();
    }


    return 0;

}

int basicSDL2cleanup(SDLContext *ctx) {
    SDL_DestroyTexture(ctx->texture);
    SDL_DestroyRenderer(ctx->renderer);
    SDL_DestroyWindow(ctx->window);
    return 0;
}

int basicSDL2mainLoop(SDLContext *ctx) {
    int quit = 0;
//

    while(!quit){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = 1;
            }
        }


        SDL_SetRenderDrawColor(ctx->renderer, 0, 0, 0, 0);
//
//        SDL_SetRenderTarget(ctx->renderer, NULL);
        SDL_RenderClear(ctx->renderer);



        SDL_RenderPresent(ctx->renderer);
        SDL_Delay(10);
    }
    return 0;
}
