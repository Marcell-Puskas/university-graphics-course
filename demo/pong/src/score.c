#include "score.h"
#include <stdio.h>

void update_score(SDL_Window *window, int p1, int p2)
{
    char title[50];
    sprintf(title, "Pong! Player1: %d, Player2: %d", p1, p2);
    SDL_SetWindowTitle(window, title);
}