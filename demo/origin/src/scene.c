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

void render_scene(const Scene* scene, const Camera* camera)
{
    draw_origin();
    draw_triangle();
    draw_chess_table();
    draw_cylinder( (vec3){0, 3.0, 0} );
    draw_cone( (vec3){0, -3.0, 0} );
    draw_center_dot(camera);

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

void draw_center_dot(Camera* c)
{
    glColor4f(0.5, 0.5, 0.5, 0.5);
    glPointSize(5.0);
    
    glBegin(GL_POINTS);
    
    glVertex3f(
        c->position.x, c->position.y, c->position.z
    );

    glEnd();
}

void draw_chess_table()
{
    
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if ((i + j) % 2)
                glColor3f(0, 0, 0);
            else 
                glColor3f(1, 1, 1);
            glBegin(GL_QUADS);
            glVertex3f((i+1)/8.0, (j+0)/8.0, 0);
            glVertex3f((i+0)/8.0, (j+0)/8.0, 0);
            glVertex3f((i+0)/8.0, (j+1)/8.0, 0);
            glVertex3f((i+1)/8.0, (j+1)/8.0, 0);
            glVertex3f((i+1)/8.0, (j+0)/8.0, 0);
            glEnd();
        }
    }

}

void draw_cylinder(vec3 pos)
{
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_TRIANGLE_STRIP);
    const int cylinder_res = 32;
    glVertex3f(pos.x + 1, pos.y + 0, pos.z + 1);
    for (size_t i = 0; i <= cylinder_res; i++)
    {
        glVertex3f(
            pos.x + cos(i * 2 * M_PI / cylinder_res), 
            pos.y + sin(i * 2 * M_PI / cylinder_res), 
            pos.z + i%2
        );
    }
    glVertex3f(pos.x + 1, pos.y + 0, pos.z + 1);
    glEnd();
}

void draw_cone(vec3 pos)
{
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(
        pos.x,
        pos.y,
        pos.z + 1
    );
    
    const int cone_res = 32;
    for (size_t i = 0; i <= cone_res; i++)
    {
        glVertex3f(
            pos.x + cos(i * 2 * M_PI / cone_res),
            pos.y + sin(i * 2 * M_PI / cone_res),
            pos.z
        );
    }
    glEnd();
}