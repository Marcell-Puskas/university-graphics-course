#ifndef CONES_H
#define CONES_H
#include "utils.h"
#include <GL/gl.h>
#include <obj/model.h>

typedef struct
{
    Model model;
    GLuint texture_id;
    vec3 *locations;
    size_t count;
} Cones;

void draw_cones(const Cones *cones);

#endif