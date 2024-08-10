#include <graphx.h>
#include <keypadc.h>
#include "paddle.h"


/* allocate bg sprite */
gfx_UninitedSprite(behind_paddle_sprite, paddle_1_width, paddle_1_height);


void init_paddle(void)
{
    behind_paddle_sprite->width = paddle_1_width;
    behind_paddle_sprite->height = paddle_1_height;
}

void move_paddle(paddle_t *paddle)
{
    kb_Scan();
    kb_key_t arrows = kb_Data[7];
    if (arrows)
    {
        if (arrows & kb_Right)
        {
            paddle->x += paddle->speed;
        }
        if (arrows & kb_Left)
        {
            paddle->x -= paddle->speed;
        }
    }

    // collisions
    if (paddle->x < 0)
    {paddle->x = 0;}
    if ((paddle->x + paddle->width) > GFX_LCD_WIDTH)
    {paddle->x = (GFX_LCD_WIDTH - paddle->width);}
}

void render_paddle(paddle_t *paddle)
{
    static uint24_t oldX = PADDLE_START_X;
    static uint24_t oldY = PADDLE_START_Y;

    /* render the background */
    gfx_Sprite(behind_paddle_sprite, oldX, oldY);

    /* get the new behind sprite */
    // gfx_GetSprite(behind_paddle_sprite, paddle->x, paddle->y);

    /* render the sprite */
    gfx_Sprite(paddle->sprite, paddle->x, paddle->y);

    oldX = paddle->x;
    oldY = paddle->y;
}
