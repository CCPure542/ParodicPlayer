#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setProgress(qint64 pos)
{
    player->setPosition(pos*1000);
    ui->timeEdit_position->setTime(QTime(0,0,0,0).addMSecs(pos*1000));
}

void MainWindow::UpdatePositon(qint64 pos)
{
    ui->slider_progress->setMaximum(player->duration() / 1000);
    ui->slider_progress->setValue(pos / 1000);
    ui->timeEdit_position->setTime(QTime(0,0,0,0).addMSecs(pos));
}

void MainWindow::setVolume(int pos)
{
    currentVolume = pos;
    audioOutput->setVolume((float)currentVolume * 0.01f);
}

void MainWindow::UpdatePosVol(int pos)
{
    ui->slider_volume->setMaximum(100);
    ui->slider_volume->setValue(pos);
}

void MainWindow::setSoundIcon(float volFloat)
{
    int volInt = volFloat * 100;
    if(volInt > 66 && !isMuted) {
        ui->btn_sound->setIcon(QIcon(":/res/icon_sound_99"));
    }
    else if(volInt > 33 && !isMuted) {
        ui->btn_sound->setIcon(QIcon(":/res/icon_sound_66"));
    }
    else if(!isMuted){
        ui->btn_sound->setIcon(QIcon(":/res/icon_sound_33"));
    }
}
