#include "mainwindow.h"

void MainWindow::setSupportSuffix() {
    lstSuffix.reserve(4);
    lstSuffix.push_back("mp4");
    lstSuffix.push_back("avi");
    lstSuffix.push_back("mp3");
    lstSuffix.push_back("wav");
}

QString MainWindow::getSupportSuffix() {
    QString str("");
    for(int i=0;i<lstSuffix.size();i++) {
        str+=lstSuffix[i];
        str+="; ";
    }
    return(str);
}

QString MainWindow::getSuffixFilter() {
    QString str("Video/Audio(*.mp4 *.avi *.mp3 *wav);;All Files(*.*)");
    return(str);
}
