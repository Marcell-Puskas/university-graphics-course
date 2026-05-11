#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "track.h"
#include "cones.h"
#include "car.h"
#include "skybox.h"
#include <GL/gl.h>

typedef struct Scene
{
    Car car;
    Track track;
    Cones cones;
    Skybox skybox;
    GLuint manual_texture;
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Update the scene.
 */
void update_scene(Scene* scene, double time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene, const Camera* camera);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/**
 * Draw camera center dot.
 */
void draw_center_dot(const Camera* c);

/**
 * Draw manual image.
 */
void draw_manual(const Scene *scene);

#endif /* SCENE_H */
