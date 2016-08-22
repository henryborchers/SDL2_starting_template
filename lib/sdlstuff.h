//
// Created by Borchers, Henry Samuel on 8/20/16.
//

#ifndef BASICSDL2C_SDLSTUFF_H
#define BASICSDL2C_SDLSTUFF_H
#include <SDL2/SDL.h>


typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    SDL_Texture *texture;
} SDLContext;

int say_hi();
int basicSDL2();
static int basicSDL2init(SDLContext *ctx);
static int basicSDL2cleanup(SDLContext *ctx);
static int basicSDL2mainLoop(SDLContext *ctx);
#endif //BASICSDL2C_SDLSTUFF_H
