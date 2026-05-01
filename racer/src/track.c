#include "track.h"
#include <obj/draw.h>

void draw_track(const Track *track)
{
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, track->texture_id);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);

    glTexCoord2f(0, 0);
    glVertex3f(-100.0, -100.0, 0);
    glTexCoord2f(1.0, 0);
    glVertex3f(100, -100.0, 0);
    glTexCoord2f(1.0, 1.0);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(100, 100, 0);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-100.0, 100, 0);
    
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);

    glPopMatrix();
}