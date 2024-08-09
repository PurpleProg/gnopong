#include <graphx.h>
#include <keypadc.h>
#include "gfx/gfx.h"
#include "paddle.h"
#include "ball.h"


void init_game(void);
void quit_game(void);


int main(void)
{
    init_game();

    init_ball();

    /* create paddle */
    paddle_t paddle = {
        PADDLE_START_X,
        PADDLE_START_Y,
        paddle_1_width,
        paddle_1_height,
        paddle_1,
        4,   // speed
    };

    /* create ball */
    vector_t dir = {1, -1};
    ball_t ball = {
        BALL_START_X,
        BALL_START_Y,
        ball_sprite_width,
        ball_sprite_height,
        ball_sprite,
        4,
        dir, // direction
    };

    do {  // mainloop
        // updates
        move_ball(&ball);
        move_paddle(&paddle);

        // render
        render_paddle(paddle);
        render_ball(&ball);
        gfx_BlitBuffer();

    } while (kb_Data[6] != kb_Clear);

    quit_game();

    return 0;
}


/* initialize screen, paddle */
void init_game(void)
{
    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    gfx_ZeroScreen();
    init_paddle();
}


/* put the LCD back in normal moder */
void quit_game(void)
{
    gfx_End();
}
