#include "cones.h"
#include <obj/draw.h>
#include <stdio.h>

void draw_cones(const Cones *cones)
{
    glPushMatrix();
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D, cones->texture_id);

    
    for (size_t i = 0; i < cones->count; i++)
    {
        if (i%2 == 0) glColor3f(0.0, 0.5, 1.0);
        else glColor3f(1.0, 1.0, 0.0);
        vec3 l = cones->locations[i];
        glTranslatef(l.x, l.y, l.z);
        draw_model(&(cones->model));
        glTranslatef(-l.x, -l.y, -l.z);
    }

    //glDisable(GL_TEXTURE_2D);
    
    glColor3f(1.0, 1.0, 1.0);
    
    glPopMatrix();
}