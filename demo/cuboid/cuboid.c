#include "cuboid.h"

void Cuboid_set(Cuboid* cuboid, double l, double w, double h) {
    if (l > 0) (*cuboid).l = l;
    if (w > 0) (*cuboid).w = w;
    if (h > 0) (*cuboid).h = h;
}

double Cuboid_volume(Cuboid* c) {
    return c->l * c->w * c->h;
}

double Cuboid_surface(Cuboid* c) {
    return (c->l * c->w + c->l * c->h + c->w * c->h) * 2;
}

bool Cuboid_has_square_side(Cuboid* c) {
    return c->l == c->w || c->l == c->h || c->w == c->h;
}