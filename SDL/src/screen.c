#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "screen.h"

/* General configuration */
#define FRAMES_PER_SECOND 60

/* Monitor configuration */
#define MONITOR_RESOLUTION_WIDTH  1920
#define MONITOR_RESOLUTION_HEIGHT 1080

static SDL_Window *win;
static SDL_Renderer *ren;

int screen_init(int monitor)
{
    if (SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Error: SDL_Init: %s\n", SDL_GetError());
        return 1;
    }

    win = SDL_CreateWindow("Game of Life",
            monitor * MONITOR_RESOLUTION_WIDTH,
            0, 640, 480, SDL_WINDOW_SHOWN);
    if (!win) {
        fprintf(stderr, "Error: SDL_CreateWindow: %s\n", SDL_GetError());
        return 1;
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!ren) {
        fprintf(stderr, "Error: SDL_CreateRenderer: %s\n", SDL_GetError());
        if (win) SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    return 0;
}

int screen_step(void)
{
    static SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT
            || (event.type == SDL_WINDOWEVENT
                && event.window.event == SDL_WINDOWEVENT_CLOSE)) {
            return 1;
        }
    }

    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
    SDL_Delay(1000 / FRAMES_PER_SECOND);

    return 0;
}

void screen_destroy(void)
{
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
