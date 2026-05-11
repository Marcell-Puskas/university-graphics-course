#include "car.h"
#include <obj/draw.h>

void draw_car(const Car *car) 
{
    glPushMatrix();
    glScalef(0.1, 0.1, 0.1);
    glRotatef(+90, 1, 0, 0);
    glTranslatef(car->pos.x, car->pos.y, car->pos.z);
    glRotatef(car->rotation.x, 1, 0, 0);
    glRotatef(car->rotation.y, 0, 1, 0);
    glRotatef(car->rotation.z, 0, 0, 1);

    glColor3f(0.0, 0.2, 1.0);

    glEnable(GL_COLOR_MATERIAL);
    // glEnable(GL_TEXTURE_2D);
    // glBindTexture(GL_TEXTURE_2D, car->texture_id);
    draw_model(&(car->model));
    // glDisable(GL_TEXTURE_2D);

    glColor3f(1.0, 1.0, 1.0);
    glPopMatrix();
}
