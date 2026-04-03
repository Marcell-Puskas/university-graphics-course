#ifndef SPHERE_H
#define SPHERE_H

#include "utils.h"
#include <GL/gl.h>

#define SPHERE_STEP 0.5

typedef struct
{
    vec3 pos;
    GLfloat radius;
    float roation;
    float speed;
} Sphere;

void init_sphere(Sphere* sphere);

void update_sphere(Sphere* sphere, double time);

void draw_sphere(Sphere* s);

#endif // SPHERE_H