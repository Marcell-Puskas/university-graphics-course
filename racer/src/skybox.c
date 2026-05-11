#include "skybox.h"
#include <obj/draw.h>

void draw_skybox(const Skybox *skybox)
{
    glPushMatrix();
    //glLoadIdentity();
    glScalef(0.05,0.05,0.05);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, skybox->texture);
    draw_model(&(skybox->model));
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}