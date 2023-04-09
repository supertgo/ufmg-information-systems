#include <SDL2/SDL.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

void koch(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int depth, double angle) {
    if (depth == 0) {
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        return;
    } else {
        int dx = x2 - x1;
        int dy = y2 - y1;
        int x3 = x1 + dx / 3;
        int y3 = y1 + dy / 3;
        int x4 = x2 - dx / 3;
        int y4 = y2 - dy / 3;
        SDL_RenderDrawLine(renderer, x3, y3, x3, y3 - dx / 3);
        SDL_RenderDrawLine(renderer, x3, y3 - dx / 3, x4, y4 - dx / 3);
        SDL_RenderDrawLine(renderer, x4, y4 - dx / 3, x4, y4);
    }
}
int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Koch curve", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    koch(renderer, 0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2, 1, 0);
    SDL_RenderPresent(renderer);
    SDL_Delay(100000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
