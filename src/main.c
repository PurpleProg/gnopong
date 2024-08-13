#include <graphx.h>
#include <keypadc.h>
#include "gfx/gfx.h"
#include "ball.h"
#include "map.h"


void init_game(void);
void render_map(bool (*map)[7][10]);


int main(void)
{
    // init the screen
    gfx_Begin();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetDrawBuffer();
    gfx_FillScreen(0);  // black

    // create white ball
    vector_t dir_white = {1, -1};
    ball_t ball_white = {
        1,
        BALL_WHITE_START_X,
        BALL_WHITE_START_Y,
        ball_sprite_white_width,
        ball_sprite_white_height,
        ball_sprite_white,
        3,   // speed
        dir_white, // direction
    };
    // create black ball
    vector_t dir_black = {-1, 1};
    ball_t ball_black = {
        0,
        BALL_BLACK_START_X,
        BALL_BLACK_START_Y,
        ball_sprite_black_width,
        ball_sprite_black_height,
        ball_sprite_black,
        3,   // speed
        dir_black, // direction
    };

    /* init the map
    width : 10*32 = 320
    height : 7*32 = 224, 16 offset
    */
    bool map[MAP_ROWS][MAP_COLUMNS] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    // mainloop
    do {
        // updates
        move_white_ball(&ball_white, &map);  // change map
        move_black_ball(&ball_black, &map);  // change map

        // render
        render_map(&map);
        render_ball(&ball_white);
        render_ball(&ball_black);

        gfx_BlitBuffer();

    } while (kb_Data[6] != kb_Clear);

    gfx_End();
    return 0;
}
