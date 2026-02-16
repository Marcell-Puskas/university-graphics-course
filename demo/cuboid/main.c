#include <stdio.h>
#include "cuboid.h"

int main() {
    Cuboid cube;
    Cuboid_set(&cube, 10, 10, 30);
    
    printf("Volume: %lf\nSurface: %lf\nis square: %d", 
        Cuboid_volume(&cube), Cuboid_surface(&cube), Cuboid_has_square_side(&cube)
    );

    return 0;
}