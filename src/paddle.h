#ifndef paddle_H
#define paddle_H

#include <stdint.h>
#include <graphx.h>
#include "gfx/gfx.h"


#define PADDLE_START_X ((GFX_LCD_WIDTH - paddle_1_width) / 2)
#define PADDLE_START_Y  GFX_LCD_HEIGHT - (paddle_1_height * 2)


typedef struct
{
    int x;
    int y;
    const uint8_t width;
    const uint8_t height;
    gfx_sprite_t *sprite;
    const uint8_t speed;
} paddle_t;


void init_paddle(void);
void move_paddle(paddle_t *paddle);
void render_paddle(paddle_t);


# endif