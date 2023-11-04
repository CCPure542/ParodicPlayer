#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::keyPressEvent(QKeyEvent * ev)
{
    if(ev->key()==Qt::Key_Space)
    {
        ui->btn_pause->click();
    }
    else if (ev->key()==Qt::Key_Right){
        ui->btn_next->click();
    }
    else if (ev->key()==Qt::Key_Left){
        ui->btn_pre->click();
    }
    else if (ev->key()==Qt::Key_O){
        ui->btn_open->click();
    }
    else if (ev->key()==Qt::Key_Delete){
        ui->btn_delete->click();
    }
    else if (ev->key()==Qt::Key_L){
        ui->btn_list->click();
    }
    else if (ev->key()==Qt::Key_X){
        ui->spinBox_pbr->setValue(ui->spinBox_pbr->value()-0.25);
    }
    else if (ev->key()==Qt::Key_C){
        ui->spinBox_pbr->setValue(ui->spinBox_pbr->value()+0.25);
    }
    else
    {
        QWidget::keyPressEvent(ev);
    }
}
