#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#define FPS 60

int main(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "Error: SDL_Init: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *win = SDL_CreateWindow("Game of Life", 0, 0, 640, 480, SDL_WINDOW_SHOWN);
    if (!win) {
        fprintf(stderr, "Error: SDL_CreateWindow: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!ren) {
        fprintf(stderr, "Error: SDL_CreateRenderer: %s\n", SDL_GetError());
        if (win) SDL_DestroyWindow(win);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    int quit = 0;
    SDL_Event event;
    while (1) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT
                || (event.type == SDL_WINDOWEVENT
                    && event.window.event == SDL_WINDOWEVENT_CLOSE)) {
                quit = 1;
            }
        }
        if (quit) break;

        SDL_RenderClear(ren);
        SDL_RenderPresent(ren);
        SDL_Delay(1000 / FPS);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return EXIT_SUCCESS;
}
