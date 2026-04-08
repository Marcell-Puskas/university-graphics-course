#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "sphere.h"
#include <GL/gl.h>

typedef struct Scene
{
    Sphere sphere;
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
 * Draw triangle.
 */
void draw_triangle();

/**
 * Draw camera center dot.
 */
void draw_center_dot(Camera* c);

/**
 * Draw chess table.
 */
void draw_chess_table();

void draw_cylinder(vec3 pos);

void draw_cone(vec3 pos);

#endif /* SCENE_H */
