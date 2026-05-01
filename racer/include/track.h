#pragma once
#include <obj/model.h>
#include <GL/gl.h>
#include "utils.h"

typedef struct {
    GLuint texture_id;
} Track;

void draw_track(const Track *track);