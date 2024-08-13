#ifndef map_H
#define map_H

#include <graphx.h>

/*
/!\ CAREFULL the tiles are drawn using gfx_FillRectangle_NoClip,
so TILE_WIDHT * MAP_ROWS should NEVER be greater than GFX_LCD_WIDTH ( =339 )
*/
#define TILE_WIDTH 32
#define TILE_HEIGHT 32
#define MAP_ROWS 7
#define MAP_COLUMNS 10
#define APPROX_CORNER 2
#define MAP_HEIGHT MAP_ROWS * TILE_HEIGHT
#define MAP_WIDTH MAP_COLUMNS * TILE_WIDTH


void render_map(bool (*map)[MAP_ROWS][MAP_COLUMNS]);

#endif
