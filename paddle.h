#ifndef PADDLE_H
#define PADDLE_H
#include "config.h"
#include<QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>

// This is the Paddle class used to manage the player and Ai paddles
class Paddle: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    Q_PROPERTY(int height READ height)
    Q_PROPERTY(int width READ width)

public: // methods
    Paddle(); // constructor
    void keyReleaseEvent(QKeyEvent *event);
    enum MoveType {UP, DOWN};
    Q_ENUM(MoveType)
    bool validMove(MoveType moveType);
    void move(MoveType moveType);
    void randomMove(qreal ballY);
    int height();
    int width();

protected: // variables
    int paddle_height = 100;
    int paddle_width = 20;
    int paddle_movestep = 15;
};

#endif // PADDLE_H
