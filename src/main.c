#include <graphx.h>
#include <keypadc.h>
#include "gfx/gfx.h"
#include "paddle.h"
#include "ball.h"
#include "map.h"


void init_game(void);
void render_map(bool (*map)[7][10]);


int main(void)
{
    init_game();

    /* create paddle */
    paddle_t paddle = {
        PADDLE_START_X,
        PADDLE_START_Y,
        paddle_1_width,
        paddle_1_height,
        paddle_1,
        3,   // speed
    };

    /* create ball */
    vector_t dir = {1, -1};
    ball_t ball = {
        BALL_START_X,
        BALL_START_Y,
        ball_sprite_width,
        ball_sprite_height,
        ball_sprite,
        3,
        dir, // direction
    };

    /*
    init the map
    width : 10*32 = 320
    height : 7*32 = 224, score on a 16 offset
     */
    // bool map[MAP_ROWS][MAP_COLUMNS] = {
    //     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    //     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    //     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    //     {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    // };
    bool map[MAP_ROWS][MAP_COLUMNS] = {
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    do {  // mainloop
        // updates
        move_paddle(&paddle);
        move_ball(&ball, &paddle, &map);  // change map

        // render
        render_map(&map);
        render_paddle(&paddle);
        render_ball(&ball);

        gfx_BlitBuffer();

    } while (kb_Data[6] != kb_Clear);

    gfx_End();
    return 0;
}


/* initialize screen, paddle */
void init_game(void)
{
    gfx_Begin();

    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_SetTransparentColor(0);  // black
    gfx_SetDrawBuffer();
    gfx_FillScreen(0);  // black

    init_paddle();
    init_ball();
}
