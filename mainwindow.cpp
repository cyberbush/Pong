#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "paddle.h"
#include "ball.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // add game pieces
    Paddle *Player = new Paddle();
    Player->setPos(5, (height() / 2.0) - Player->height());
    Player->setBrush(Qt::blue);
    Player->setFlag(QGraphicsItem::ItemIsFocusable);
    Player->setFocus();

    Paddle *Ai = new Paddle();
    Ai->setPos(width() - Ai->width() - 5, (height() / 2) - Ai->height());

    Ball *ball = new Ball();
    ball->setPaddles(Player, Ai);
    ball->setPos(Player->x() + ball->width() + 12, Player->y() + Player->height() / 2);

    // set up the game scene
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());
    scene->addItem(Player);
    scene->addItem(Ai);
    scene->addItem(ball);


    // set up the game view
    ui->gameScreen->setScene(scene);
    ui->gameScreen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameScreen->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameScreen->setGeometry(0, 0, width(), height());
    ui->gameScreen->setFixedSize(width(), height());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionHelp_triggered()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("Help");
    msgBox->setText("Use the Up and Down arrow keys to move the paddle and hit the ball across the screen!");
    msgBox->setInformativeText("Everytime the ball passes through the other persons side you score a point! The first one to 3 points wins!");
    msgBox->exec();
}

