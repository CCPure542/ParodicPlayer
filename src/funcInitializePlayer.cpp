#include "mainwindow.h"
#include "qgraphicsview.h"
#include "ui_mainwindow.h"
void MainWindow::initializePlayer() {

    audioOutput =  new QAudioOutput(this);
    player = new QMediaPlayer(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    initializePixmapItem(false);

    player->setVideoOutput(videoItem);
    player->setAudioOutput(audioOutput);
}

void MainWindow::initializeVideoItem() {
    scene->clear();
    videoItem = new QGraphicsVideoItem;
    videoItem->setSize(QSize(ui->graphicsView->width(),ui->graphicsView->height()));
    videoItem->setFlags(
        QGraphicsVideoItem::ItemIsMovable
        |QGraphicsPathItem::ItemIsSelectable
        |QGraphicsItem::ItemIsFocusable);
    scene->addItem(videoItem);
    player->setVideoOutput(videoItem);
}

void MainWindow::initializePixmapItem(bool flag) {
    scene->clear();
    pixmapItem = new QGraphicsPixmapItem;
    if(flag) pixmapItem->setPixmap(QPixmap(":/res/audioplay.png"));
    else pixmapItem->setPixmap(QPixmap(":/res/logo.png"));
    scene->addItem(pixmapItem);
}
