#pragma once
#include "cones.h"

/// @brief Reads in cones from a file
/// @param cones 
/// @param filename 
/// @return 0: OK; 1: File missing; 2: Empty file; 3: Less lines than specified; 4: No character separator
int read_cones(Cones *cones, const char *filename);