#include "scene.h"
#include "sphere.h"

void init_scene(Scene* scene)
{
    init_sphere(&scene->sphere);  
}

void update_scene(Scene* scene, double time)
{
    update_sphere(&scene->sphere, time);
}

void render_scene(const Scene* scene)
{
    draw_origin();
    draw_triangle();

    glColor3f(0.5, 0.5, 0.5);
    draw_sphere(&scene->sphere);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0, 0, 0);
    draw_sphere(&scene->sphere);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    
    glBegin(GL_QUADS);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
    glVertex3f(1, 0, 1);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);
    glVertex3f(1, 0, 1);
    glVertex3f(1, 0, 0);

    glEnd();

}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void draw_triangle()
{
    glBegin(GL_TRIANGLES);
    
    glColor3f(1, 1, 0);
    glVertex3f(1, 0, 0);
    glColor3f(1, 0, 1);
    glVertex3f(0, 1, 0);
    glColor3f(0, 1, 1);
    glVertex3f(0, 0, 1);

    glEnd();
}
