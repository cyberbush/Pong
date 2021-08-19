#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include "paddle.h"

// This is the Ball class thats used for the ball object

class Ball: public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT

    Q_PROPERTY(int width READ width)
    Q_PROPERTY(int height READ height)
    Q_PROPERTY(int speed READ speed)

public:
    Ball();
    void setPaddles(Paddle *player, Paddle *computer);
    bool insideBoard();
    int width();
    int height();
    int speed();

public slots:
    void move();


private:
    Paddle *Player;
    Paddle *Ai;
    int ball_width = 15;
    int ball_height = 15;
    qreal dx, dy, ball_speed;
};

#endif // BALL_H
