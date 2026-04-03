#include "sphere.h"

#define _USE_MATH_DEFINES
#include <math.h>

void init_sphere(Sphere* sphere)
{
    *sphere = (Sphere){
        .pos = (vec3){ 0.5, 0.5, 0.5 },
        .radius = 0.5,
        .speed = 0.1,
    };
}

void update_sphere(Sphere* sphere, double time)
{
    sphere->roation += sphere->speed * time;
    if (sphere->roation > 360) {
        sphere->roation -= 360;
    }
}

void draw_sphere(Sphere* s)
{
    glBegin(GL_QUAD_STRIP);
    glColor3f(0.5, 0.5, 0.5);

    for (GLfloat i = -M_PI_2; i < M_PI_2; i += SPHERE_STEP)
    {
        for (GLfloat j = s->roation; j < s->roation + 2*M_PI; j += SPHERE_STEP)
        {
            glVertex3f(s->pos.x + cos(j) * cos(i) * s->radius, s->pos.y + sin(j) * cos(i) * s->radius, s->pos.z + sin(i) * s->radius);
            glVertex3f(s->pos.x + cos(j) * cos(i + SPHERE_STEP) * s->radius, s->pos.y + sin(j) * cos(i + SPHERE_STEP) * s->radius, s->pos.z + sin(i + SPHERE_STEP) * s->radius);
        }   
    }
    
    glEnd();
}