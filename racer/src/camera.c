#include "camera.h"

#include <GL/gl.h>

#include <math.h>

void init_camera(Camera* camera)
{
    *camera = (Camera){
        .position.x = 0.5,
        .position.y = 0.5,
        .position.z = 0.5,
        .rotation.x = 0.0,
        .rotation.y = 0.0,
        .rotation.z = 0.0,
        .speed.x = 0.0,
        .speed.y = 0.0,
        .speed.z = 0.0,
        .distance = 2.0,
    };
}

void update_camera(Camera* camera, double time)
{
    double angle;
    double side_angle;
    
    angle = degree_to_radian(camera->rotation.z);
    side_angle = degree_to_radian(camera->rotation.z + 90.0);
    
    camera->position.x += cos(angle) * camera->speed.y * time;
    camera->position.y += sin(angle) * camera->speed.y * time;
    camera->position.x += cos(side_angle) * camera->speed.x * time;
    camera->position.y += sin(side_angle) * camera->speed.x * time;
    camera->position.z += camera->speed.z * time;
    camera->rotation.z += camera->rotation_speed * time;
}

void set_view(const Camera* camera)
{
    double x_angle, z_angle;

    x_angle = degree_to_radian(camera->rotation.x);
    z_angle = degree_to_radian(camera->rotation.z);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->rotation.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->rotation.z - 90), 0, 0, 1.0);
    glTranslatef(
        -camera->position.x + camera->distance * cos(z_angle) * cos(x_angle), 
        -camera->position.y + camera->distance * sin(z_angle) * cos(x_angle), 
        -camera->position.z + camera->distance * sin(x_angle)
    );
}

void rotate_camera(Camera* camera, double horizontal, double vertical)
{
    camera->rotation.z += horizontal;
    camera->rotation.x += vertical;

    if (camera->rotation.z < 0) {
        camera->rotation.z += 360.0;
    }

    if (camera->rotation.z > 360.0) {
        camera->rotation.z -= 360.0;
    }

    if (camera->rotation.x < 0) {
        camera->rotation.x += 360.0;
    }

    if (camera->rotation.x > 360.0) {
        camera->rotation.x -= 360.0;
    }
}

void set_camera_speed(Camera* camera, double speed)
{
    camera->speed.y = speed;
}

void set_camera_side_speed(Camera* camera, double speed)
{
    camera->speed.x = speed;
}

void set_camera_vertical_speed(Camera* camera, double speed)
{
    camera->speed.z = speed;
}

void set_camera_rotation_speed(Camera* camera, double speed)
{
    camera->rotation_speed = speed;
}