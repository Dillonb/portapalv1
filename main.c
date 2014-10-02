#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#define TRUE 1
#define FALSE 0

const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 240;

typedef struct node_t {
    struct node_t* next;
    int test2;
} node;

int main(int argc, char** argv) {
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    int quit = FALSE;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL error: %s\n", SDL_GetError());
        return 0;
    }
    else {
        window = SDL_CreateWindow("Poopboy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! Error: %s\n", SDL_GetError());
            return 0;
        }
        else {
            screenSurface = SDL_GetWindowSurface(window);

            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));

            SDL_UpdateWindowSurface(window);
        }
    }

    SDL_Event e;
    while (!quit) {
        SDL_Delay(100);
        while (SDL_PollEvent(&e) != 0) {
            switch(e.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_KEYDOWN:
                    printf("Key down.\n");
                    switch (e.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = 1;
                            break;
                        default:
                            printf("%i\n", e.key.keysym.sym);
                    }
                    break;
                case SDL_KEYUP:
                    printf("Key up.\n");
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
