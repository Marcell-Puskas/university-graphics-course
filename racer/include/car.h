#pragma once
#include <obj/model.h>
#include <GL/gl.h>
#include "utils.h"

typedef struct {
    Model model;
    GLuint texture_id;
    vec3 pos;
    vec3 rotation;
} Car;

void draw_car(const Car *car);