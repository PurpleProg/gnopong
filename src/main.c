#include "paddle.h"
#include "ball.h"

int main(void)
{

    move_paddle();
    move_ball();

    render_paddle();
    render_ball();

    return 0;
}