#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "line.h"
#include <stdbool.h>
#include "color.h"

#define MAX_LINE_COUNT 500

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static float x_mouse, y_mouse;
static float x_line_start, y_line_start;
static bool line_started = false;
Line lines[MAX_LINE_COUNT];
int line_count = 0;

Color selectabel_colors[] = {
    COLOR_RED, COLOR_YELLOW, COLOR_GREEN, COLOR_CYAN, COLOR_BLUE, COLOR_WHITE, COLOR_BLACK
};
const int selectable_color_count = 7;
int selected_color = 0;
int _new_color = 0;

#define COLOR_BUTTON_PAD 10
static SDL_FRect color_select_rect = {
    .h = 100,
    .w = 100,
};

void click_line() {
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
            .color = selectabel_colors[selected_color],
        };
        line_started = false;
    }
}

void click_color() {
    if (y_mouse < COLOR_BUTTON_PAD) return;
    if (((int)x_mouse - COLOR_BUTTON_PAD) % (int)(color_select_rect.w + COLOR_BUTTON_PAD) > color_select_rect.w) return;
    _new_color = (int)x_mouse / (int)(color_select_rect.w + COLOR_BUTTON_PAD);
    if (_new_color >= selectable_color_count) return;
    selected_color = _new_color;
    SDL_Log("Selected color: %d", selected_color);
}

/* This function runs once at startup. */
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
        if (y_mouse > COLOR_BUTTON_PAD + color_select_rect.h) {
            click_line();
        } else {
            click_color();
        }
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{    
    SDL_SetRenderDrawColor(renderer, 33, 33, 33, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    
    for (Line *l = lines; l < lines + line_count; l++)
    {
         SDL_SetRenderDrawColor(renderer, l->color.r, l->color.g, l->color.b, SDL_ALPHA_OPAQUE);
        SDL_RenderLine(renderer, l->x1, l->y1, l->x2, l->y2);
    }

    for (int i = 0; i < selectable_color_count; i++)
    {
        Color c = selectabel_colors[i];
        color_select_rect.x = COLOR_BUTTON_PAD + (i * (color_select_rect.w + COLOR_BUTTON_PAD));
        color_select_rect.y = COLOR_BUTTON_PAD;
        SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &color_select_rect);
    }
    

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {}
