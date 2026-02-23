#ifndef COLOR_H
#define COLOR_H

typedef struct
{
    int r;
    int g;
    int b;
} Color;

#define COLOR_RED     (Color){ 255, 0, 0 }
#define COLOR_GREEN   (Color){ 0, 255, 0 }
#define COLOR_BLUE     (Color){ 0, 0, 255 }
#define COLOR_YELLOW  (Color){ 255, 255, 0 }
#define COLOR_CYAN    (Color){ 0, 255, 255 }
#define COLOR_PURPLE  (Color){ 255, 0, 255 }
#define COLOR_BLACK   (Color){ 0, 0, 0 }
#define COLOR_WHITE   (Color){ 255, 255, 255 }

#endif // COLOR_H