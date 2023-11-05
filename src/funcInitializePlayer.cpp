#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::initializePlayer()
{
    audioOutput =  new QAudioOutput(this);
    player = new QMediaPlayer(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    initializePixmapItem(false);

    player->setVideoOutput(videoItem);
    player->setAudioOutput(audioOutput);
}

void MainWindow::initializeVideoItem()
{
    if(videoItem!=nullptr)
    {
        delete videoItem;
        videoItem = nullptr;
    }
    if(pixmapItem!=nullptr)
    {
        delete pixmapItem;
        pixmapItem = nullptr;
    }
    scene->clear();
    videoItem = new QGraphicsVideoItem;
    videoItem->setFlags(
        QGraphicsVideoItem::ItemIsMovable
        |QGraphicsPathItem::ItemIsSelectable
        |QGraphicsItem::ItemIsFocusable);
    scene->addItem(videoItem);
    videoItem->setSize(QSize(ui->graphicsView->width(),ui->graphicsView->height()));
    player->setVideoOutput(videoItem);
}

void MainWindow::initializePixmapItem(bool flag)
{
    if(videoItem!=nullptr)
    {
        delete videoItem;
        videoItem = nullptr;
    }
    if(pixmapItem!=nullptr)
    {
        delete pixmapItem;
        pixmapItem = nullptr;
    }
    scene->clear();
    pixmapItem = new QGraphicsPixmapItem;
    if(flag) pixmapItem->setPixmap(QPixmap(":/res/audioplay.png"));
    else pixmapItem->setPixmap(QPixmap(":/res/logo.png"));
    scene->addItem(pixmapItem);
}
