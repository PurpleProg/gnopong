#include <math.h>
#include <graphx.h>
#include <keypadc.h>
#include "ball.h"
#include "map.h"


// move the white ball and handle the collisions
void move_white_ball(ball_t *ball, bool (*map)[MAP_ROWS][MAP_COLUMNS]) {
    // move it
    ball->x += ball->speed * ball->direction.x;
    ball->y += ball->speed * ball->direction.y;


    // check collision with the map
    bool collided = false;
    for (uint8_t row = 0; ((row < MAP_ROWS) && !collided); row++) {
        for (uint8_t column = 0; ((column < MAP_COLUMNS) && !collided); column++) {
            int24_t tile_x = column * TILE_WIDTH;
            int24_t tile_y = row * TILE_HEIGHT;
            if ((*map)[row][column] && gfx_CheckRectangleHotspot(ball->x, ball->y, ball->width, ball->height, tile_x, tile_y, TILE_WIDTH, TILE_HEIGHT)) {
                collided = true;
                (*map)[row][column] = 0;


                // get relative posision
                uint8_t delta_x;
                if (ball->direction.x > 0) {
                    delta_x = (ball->x + ball->width) - tile_x;
                } else {
                    delta_x = (tile_x + TILE_WIDTH) - ball->x;
                }
                uint8_t delta_y;
                if (ball->direction.y > 0) {
                    delta_y = (ball->y + ball->height) - tile_y;
                } else {
                    delta_y = (tile_y + TILE_HEIGHT) - ball->y;
                }

                // update ball direction
                if (delta_x < delta_y) {
                    ball->direction.x *= -1;
                }
                else if (delta_y < delta_x) {
                    ball->direction.y *= -1;
                }
                else {
                    ball->direction.x *= -1;
                    ball->direction.y *= -1;
                }
            }
        }
    }

    // check collisions whith walls
    if (ball->x < 0) {ball->x = 0; ball->direction.x *= -1;}
    if ((ball->x + ball->width) > GFX_LCD_WIDTH) {ball->x = (GFX_LCD_WIDTH - ball->width); ball->direction.x *= -1;}
    if (ball->y < 0) {ball->y = 0; ball->direction.y *= -1;}
    // sing MAP_HEIGHT cause 32 is'nt a multiple of 240
    if ((ball->y + ball->height) > MAP_HEIGHT) {ball->y = (MAP_HEIGHT - ball->height); ball->direction.y *= -1;}
}


// move the white ball and handle the collisions
void move_black_ball(ball_t *ball, bool (*map)[MAP_ROWS][MAP_COLUMNS]) {
    // move it
    ball->x += ball->speed * ball->direction.x;
    ball->y += ball->speed * ball->direction.y;

    // check collision with the map
    for (uint8_t row = 0; ((row < MAP_ROWS)); row++) {
        for (uint8_t column = 0; (column < MAP_COLUMNS); column++) {
            int24_t tile_x = column * TILE_WIDTH;
            int24_t tile_y = row * TILE_HEIGHT;
            if (!((*map)[row][column]) && gfx_CheckRectangleHotspot(ball->x, ball->y, ball->width, ball->height, tile_x, tile_y, TILE_WIDTH, TILE_HEIGHT)) {
                (*map)[row][column] = !ball->color;


                // get relative posision
                uint8_t delta_x;
                if (ball->direction.x > 0) {
                    delta_x = (ball->x + ball->width) - tile_x;
                } else {
                    delta_x = (tile_x + TILE_WIDTH) - ball->x;
                }
                uint8_t delta_y;
                if (ball->direction.y > 0) {
                    delta_y = (ball->y + ball->height) - tile_y;
                } else {
                    delta_y = (tile_y + TILE_HEIGHT) - ball->y;
                }

                // update ball direction
                if (delta_x < delta_y) {
                    ball->direction.x *= -1;
                }
                else if (delta_y < delta_x) {
                    ball->direction.y *= -1;
                }
                else {
                    ball->direction.x *= -1;
                    ball->direction.y *= -1;
                }
            }
        }
    }

    // check collisions whith walls
    if (ball->x < 0) {ball->x = 0; ball->direction.x *= -1;}
    if ((ball->x + ball->width) > GFX_LCD_WIDTH) {ball->x = (GFX_LCD_WIDTH - ball->width); ball->direction.x *= -1;}
    if (ball->y < 0) {ball->y = 0; ball->direction.y *= -1;}
    // sing MAP_HEIGHT cause 32 is'nt a multiple of 240
    if ((ball->y + ball->height) > MAP_HEIGHT) {ball->y = (MAP_HEIGHT - ball->height); ball->direction.y *= -1;}
}


void render_ball(ball_t *ball)
{
    gfx_Sprite(ball->sprite, ball->x, ball->y);
}
