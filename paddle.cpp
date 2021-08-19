#include "paddle.h"
#include <QBrush>

// These are the definitions for the Paddle class methods

Paddle::Paddle()
{
    setRect(0, 0, paddle_width, paddle_height);
    setBrush((QBrush)Qt::black);
}

void Paddle::move(Paddle::MoveType moveType)
{
    if(validMove(moveType) && moveType == UP)
        setPos(x(), y() - paddle_movestep);
    else if(validMove(moveType) && moveType == DOWN)
        setPos(x(), y() + paddle_movestep);
}

void Paddle::randomMove(qreal ballY)
{
    // moves realitive to the ball's y position 
    MoveType m = ((y() - ballY) > -10) ? UP : DOWN;
    move(m);
}

void Paddle::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        move(UP);
        break;
    case Qt::Key_Down:
        move(DOWN);
        break;
    default:
        break;
    }
}

bool Paddle::validMove(Paddle::MoveType moveType)
{
    if(moveType == UP) return (y() - paddle_movestep) >= 0;
    else if(moveType == DOWN) return (y() + paddle_movestep) <=460;
    else return false;
}

int Paddle::width()
{
    return paddle_width;
}

int Paddle::height()
{
    return paddle_height;
}
