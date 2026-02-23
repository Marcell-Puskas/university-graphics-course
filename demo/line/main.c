#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "line.h"
#include <stdbool.h>

#define MAX_LINE_COUNT 500

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

float x_mouse, y_mouse;
Line lines[MAX_LINE_COUNT];
int line_count = 0;
float x_line_start, y_line_start;
bool line_started = false;


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    int i;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("Line editor", 1280, 700, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    SDL_SetRenderLogicalPresentation(renderer, 1280, 700, SDL_LOGICAL_PRESENTATION_LETTERBOX);

    SDL_Cursor *cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_CROSSHAIR);
    if (!cursor) {
        SDL_Log("Couldn't create system crosshair cursor: %s", SDL_GetError());
    } else {
        if (!SDL_SetCursor(cursor)) {
            SDL_Log("Couldn't set crosshair cursor: %s", SDL_GetError());
        }
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    } else if(event->type == SDL_EVENT_MOUSE_BUTTON_UP) {
        SDL_GetMouseState(&x_mouse, &y_mouse);
        SDL_Log("Mouse position: %lf; %lf", x_mouse, y_mouse);
        if (!line_started) {
            x_line_start = x_mouse;
            y_line_start = y_mouse;
            line_started = true;
        } else {
            lines[line_count++] = (Line){
                .x1 = x_line_start,
                .y1 = y_line_start,
                .x2 = x_mouse,
                .y2 = y_mouse,
            };
            line_started = false;
        }
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_SetRenderDrawColor(renderer, 33, 33, 33, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    
    for (Line *cline = lines; cline < lines + line_count; cline++)
    {
        SDL_RenderLine(renderer, cline->x1, cline->y1, cline->x2, cline->y2);
    }

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {}
