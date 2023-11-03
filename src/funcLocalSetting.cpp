#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::setDefaultValue()
{
    /* Assign Default */
    folderPath = QDir::homePath();
    currentVolume = 100;
    isMuted = false;
    currentPBR = 1.0;

    QString settingFile("Setting.ini");

    if(QFile::exists(settingFile))
    {
        QFile file(settingFile);
        file.open(QIODevice::ReadOnly);
        QString strPath = QString(file.readLine());
        strPath.removeLast();
        QString strVolumn = QString(file.readLine());
        strVolumn.removeLast();
        QString strIsMuted = QString(file.readLine());
        folderPath = strPath;
        currentVolume = strVolumn.toFloat();
        isMuted = strIsMuted.toInt();
        file.close();
    }
    else
    {
        QFile file(settingFile);
        file.open(QIODevice::WriteOnly);
        QString strInput = QString("%1\n%2\n%3").arg(folderPath).arg(currentVolume).arg(isMuted);
        const char * chrsInput = strInput.toStdString().c_str();
        file.write(chrsInput);
        file.close();
    }

    /*UI*/
    audioOutput->setVolume((float)currentVolume * 0.01f);
    audioOutput->setMuted(isMuted);
    if(isMuted) ui->btn_sound->setIcon(QIcon(":/res/icon_sound.png"));
    else
    {
        setSoundIcon(currentVolume);
        UpdatePosVol(currentVolume);
    }
}

void MainWindow::setFolderPath(QFileInfo info)
{
    folderPath = info.path();
    QFile file("Setting.ini");
    file.open(QIODevice::WriteOnly);
    QString strInput = QString("%1\n%2\n%3").arg(folderPath).arg(currentVolume).arg(isMuted);
    const char * chrsInput = strInput.toStdString().c_str();
    file.write(chrsInput);
    file.close();
}

void MainWindow::saveDefaultValue()
{
    QFile file("Setting.ini");
    file.open(QIODevice::WriteOnly);
    QString strInput = QString("%1\n%2\n%3").arg(folderPath).arg(currentVolume).arg(isMuted);
    const char * chrsInput = strInput.toStdString().c_str();
    file.write(chrsInput);
    file.close();
}
