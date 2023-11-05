#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::keyPressEvent(QKeyEvent * ev)
{
    if(ev->key()==Qt::Key_Space)
    {
        ui->btn_pause->click();
    }
    else if (ev->key()==Qt::Key_Right && ev->modifiers() == (Qt::AltModifier))
    {
        emit ui->btn_next->signalListJumpPlay();
    }
    else if (ev->key()==Qt::Key_Left && ev->modifiers() == (Qt::AltModifier))
    {
        emit ui->btn_pre->signalListJumpPlay();
    }
    else if (ev->key()==Qt::Key_Right)
    {
        ui->btn_next->click();
    }
    else if (ev->key()==Qt::Key_Left)
    {
        ui->btn_pre->click();
    }
    else if (ev->key()==Qt::Key_Up)
    {
        int val = ui->slider_volume->value();
        if(val>=95) {val=100;}
        else {val+=5;}
        ui->slider_volume->setValue(val);
    }
    else if (ev->key()==Qt::Key_Down)
    {
        int val = ui->slider_volume->value();
        if(val<=5) {val=0;}
        else {val-=5;}
        ui->slider_volume->setValue(val);
    }
    else if (ev->key()==Qt::Key_O)
    {
        ui->btn_open->click();
    }
    else if (ev->key()==Qt::Key_Delete)
    {
        ui->btn_delete->click();
    }
    else if (ev->key()==Qt::Key_L)
    {
        ui->btn_list->click();
    }
    else if (ev->key()==Qt::Key_X)
    {
        ui->spinBox_pbr->setValue(ui->spinBox_pbr->value()-0.25);
    }
    else if (ev->key()==Qt::Key_C)
    {
        ui->spinBox_pbr->setValue(ui->spinBox_pbr->value()+0.25);
    }
    else if (ev->key()==Qt::Key_M)
    {
        ui->btn_sound->click();
    }
    else
    {
        QWidget::keyPressEvent(ev);
    }
}
