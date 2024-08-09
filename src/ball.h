#ifndef ball_H
#define ball_H

#include <stdint.h>


void move_ball(void);
void render_ball(void);


typedef struct
{
    int x;
    int y;
    uint8_t width;
    uint8_t height;
} ball_t;

extern ball_t ball;


#endif