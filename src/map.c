#include "map.h"


void render_map(bool (*map)[MAP_ROWS][MAP_COLUMNS])
{
    for (uint8_t row = 0; row < MAP_ROWS; row++)
    {
        for (uint8_t column = 0; column < MAP_COLUMNS; column++)
        {
            if ((*map)[row][column] == 1) {gfx_SetColor(1);}
            else {gfx_SetColor(0);}
            gfx_FillRectangle_NoClip(column * TILE_WIDTH, row * TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
        }
    }
}