#ifndef ball_H
#define ball_H

#include <stdint.h>
#include <graphx.h>
#include "gfx/gfx.h"
#include "paddle.h"
#include "map.h"


#define BALL_WHITE_START_X ((GFX_LCD_WIDTH - ball_sprite_white_width) / 2)
#define BALL_BLACK_START_X ((GFX_LCD_WIDTH - ball_sprite_black_width) / 2)
#define BALL_WHITE_START_Y  GFX_LCD_HEIGHT - (ball_sprite_white_height * 4)
#define BALL_BLACK_START_Y  ball_sprite_white_height * 4

typedef struct
{
    int8_t x;
    int8_t y;
} vector_t;


typedef struct
{
    bool color;
    int x;
    int y;
    const uint8_t width;
    const uint8_t height;
    gfx_sprite_t *sprite;
    uint8_t speed;
    vector_t direction;
} ball_t;


void move_white_ball(ball_t *ball, paddle_t *paddle, bool (*map)[MAP_ROWS][MAP_COLUMNS]);
void move_black_ball(ball_t *ball, bool (*map)[MAP_ROWS][MAP_COLUMNS]);
void render_ball(ball_t *ball);


#endif