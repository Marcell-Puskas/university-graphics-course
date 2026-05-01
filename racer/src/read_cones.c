#include "read_cones.h"
#include <stdio.h>
#include <stdlib.h>

/// @brief Reads in cones from a file
/// @param cones 
/// @param filename 
/// @return 0: OK; 1: File missing; 2: Empty file; 3: Less lines than specified; 4: No character separator
int read_cones(Cones *cones, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file) return 1;
    char line[1024];
    if (!fgets(line, 1024, file)) return 2;
    cones->count = atoi(line);
    cones->locations = malloc(sizeof(vec3) * cones->count);
    for (size_t i = 0; i < cones->count; i++)
    {
        if (!fgets(line, 1024, file)) return 3;
        char *seperator = line;
        while (*seperator != '\0' && *seperator != ';')
        {
            seperator++;
        }
        if (*seperator != ';') return 4;
        *seperator++ = '\0';
        cones->locations[i] = (vec3){
            .x = atof(line),
            .y = atof(seperator),
            .z = 0,
        };
    }

    fclose(file);
    return 0;
}