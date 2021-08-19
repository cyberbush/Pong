#ifndef AI_MOVEMENT_H
#define AI_MOVEMENT_H

#include "paddle.h"
#include "ball.h"


class Ai_movement
{
public:
    Ai_movement();
    void move(Paddle *computer);

protected:
    qreal Ai_speed;
};

#endif // AI_MOVEMENT_H
