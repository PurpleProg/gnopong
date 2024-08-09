#ifndef paddle_H
#define paddle_H

#include <stdint.h>
#include "defines.h"


void move_paddle(void);
void render_paddle(void);

typedef struct {
    int x;
    int y;
    const uint8_t width;
    const uint8_t height;
    // hitbox_t hitbox;
} paddle_t;

extern paddle_t paddle;


# endif