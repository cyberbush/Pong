#include "Ai_movement.h"

// Manage the Ai's movements speed and update its position

Ai_movement::Ai_movement()
{
    Ai_speed = 20;
}

void Ai_movement::move(Paddle *computer)
{
    qreal dy = -(rand() % 2) + 1;
    computer->setPos(computer->x(), computer->y() + (Ai_movement::Ai_speed * dy));
}
