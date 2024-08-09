#include <graphx.h>
#include <keypadc.h>
#include "ball.h"
#include "paddle.h"
#define PI 3.1415926535
#include <math.h>


/* allocate bg sprite */
gfx_UninitedSprite(behind_ball_sprite, ball_sprite_width, ball_sprite_height);


void init_ball(void)
{
    behind_ball_sprite->width = ball_sprite_width;
    behind_ball_sprite->height = ball_sprite_height;
}


void move_ball(ball_t *ball, paddle_t *paddle)
{
    // move it
    ball->x += ball->speed * ball->direction.x;
    ball->y += ball->speed * ball->direction.y;

    // check collision with the paddle
    if (gfx_CheckRectangleHotspot(ball->x, ball->y, ball->width, ball->height, paddle->x, paddle->y, paddle->width, paddle->height))
    {
        ball->direction.y = -1;
    }

    // check collisions whith walls
    if (ball->x < 0) {ball->x = 0; ball->direction.x *= -1;}
    if ((ball->x + ball->width) > GFX_LCD_WIDTH) {ball->x = (GFX_LCD_WIDTH - ball->width); ball->direction.x *= -1;}
    if (ball->y < 0) {ball->y = 0; ball->direction.y *= -1;}
    if ((ball->y + ball->height) > GFX_LCD_HEIGHT) {ball->y = (GFX_LCD_HEIGHT - ball->height); ball->direction.y *= -1;}
}

void render_ball(ball_t *ball)
{
    static int oldX = BALL_START_X;
    static int oldY = BALL_START_Y;

    /* erase old sprite */
    gfx_Sprite(behind_ball_sprite, oldX, oldY);

    /* get new behind sprite */
    gfx_GetSprite(behind_ball_sprite, ball->x, ball->y);

    /* render the new sprite*/
    gfx_Sprite(ball->sprite, ball->x, ball->y);

    oldX = ball->x;
    oldY = ball->y;
}
