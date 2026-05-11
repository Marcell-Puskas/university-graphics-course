#pragma once

#include <GL/gl.h>
#include <obj/model.h>

typedef struct
{
    Model model;
    GLuint texture;
} Skybox;

void draw_skybox(const Skybox *skybox);