#ifndef ball_H
#define ball_H

#include <stdint.h>
#include <graphx.h>
#include "gfx/gfx.h"
#include "paddle.h"


#define BALL_START_X ((GFX_LCD_WIDTH - ball_sprite_width) / 2)
#define BALL_START_Y  GFX_LCD_HEIGHT - (ball_sprite_height * 4)


typedef struct
{
    int8_t x;
    int8_t y;
} vector_t;


typedef struct
{
    int x;
    int y;
    const uint8_t width;
    const uint8_t height;
    gfx_sprite_t *sprite;
    uint8_t speed;
    vector_t direction;
} ball_t;


void init_ball(void);
void move_ball(ball_t *ball, paddle_t *paddle);
void render_ball(ball_t *ball);


#endif