#ifndef DG_WORLD_GRID_H
#define DG_WORLD_GRID_H

#include <linmath/linmath.h>

typedef int ivec2[2];

enum
{
    CHUNK_X = 16,
    CHUNK_Y = 256,
    CHUNK_Z = 16,
};

void world_grid_pos_to_chunk_coordinate(vec3 pos, ivec2 chunk_coord);
void world_grid_loop_over_chunk_relative_to_origin(ivec2 chunk_coord);

#endif
