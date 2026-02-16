#ifndef CUBOID_H
#define CUBOID_H

#include <stdbool.h>

typedef struct {
    double l;
    double w;
    double h;
} Cuboid;

void Cuboid_set(Cuboid* cuboid, double l, double w, double h);

double Cuboid_volume(Cuboid* c);

double Cuboid_surface(Cuboid* c);

bool Cuboid_has_square_side(Cuboid* c);

#endif