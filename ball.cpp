#include "ball.h"
#include "config.h"
#include <QBrush>
#include <QTimer>
#include <QList>

// These are the definitions for the Ball class

Ball::Ball()
{
    setRect(0, 0, ball_width, ball_height);
    setBrush((QBrush)Qt::yellow);
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(60);
    dx = -1;
    dy = -1;
    ball_speed = 16;
}

void Ball::setPaddles(Paddle *p, Paddle *a)
{
    Player = p;
    Ai = a;
}

bool Ball::insideBoard()
{
    return true;
}

int Ball::width()
{
    return ball_width;
}

int Ball::height()
{
    return ball_height;
}

int Ball::speed()
{
    return ball_speed;
}

void Ball::move()
{
    // When the ball collides with a paddle
    if(collidesWithItem(Ai) || collidesWithItem(Player)){
        dx = -dx;
        dy = -(rand() % 2) + 1; // random y
    }
    // if ball hits top/bottom wall it 'bounces' off
    else if(y()>BOARD_HEIGHT - PADDLE_HEIGHT || y()<CUSHION) {
        dy = -dy;
    }
    // check if Ball leaves bounds on left/right
    else if(x()>BOARD_WIDTH - PADDLE_WIDTH || x()<CUSHION){
        //dx = -dx;
    }
    setPos(x() + (ball_speed * dx), y() + (ball_speed * dy));
    Ai->randomMove(y());
}
