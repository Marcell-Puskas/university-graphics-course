#include "scene.h"
#include <obj/load.h>
#include "texture.h"
#include "read_cones.h"

void init_scene(Scene* scene)
{
    scene->car = (Car){0};
    load_model(&(scene->car.model), "assets/models/f1_car.obj");
    // scene->car.texture_id = load_texture("assets/textures/Car.png");

    scene->track.texture_id = load_texture("assets/textures/track.jpg");

    load_model(&(scene->cones.model), "assets/models/cone.obj");
    scene->cones.texture_id = load_texture("assets/textures/cone.png");
    
    scene->manual_texture = load_texture("assets/textures/manual.png");

    load_model(&(scene->skybox.model), "assets/models/skybox.obj");
    scene->skybox.texture = load_texture("assets/textures/skybox.png");

    read_cones(&scene->cones, "cones.csv");
}

void update_scene(Scene* scene, double time)
{
}

void render_scene(const Scene* scene, const Camera* camera)
{
    if (camera->manual)
    {
        draw_manual(scene);
    }
    draw_origin();
    
    draw_track(&scene->track);

    draw_cones(&scene->cones);
    
    draw_car(&scene->car);
    
    draw_center_dot(camera);

    draw_skybox(&scene->skybox);
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
    glColor3f(1.0, 1.0, 1.0);
}

void draw_center_dot(const Camera* c)
{
    glColor4f(0.5, 0.5, 0.5, 0.5);
    glPointSize(5.0);
    
    glBegin(GL_POINTS);
    
    glVertex3f(
        c->position.x, c->position.y, c->position.z
    );

    glEnd();

    glColor3f(1.0, 1.0, 1.0);
}

void draw_manual(const Scene *scene)
{
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, scene->manual_texture);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-1, 1, -3);
    glTexCoord2f(1, 0);
    glVertex3f(1, 1, -3);
    glTexCoord2f(1, 1);
    glVertex3f(1, -1, -3);
    glTexCoord2f(0, 1);
    glVertex3f(-1, -1, -3);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
