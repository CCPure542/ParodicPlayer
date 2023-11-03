#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QScreen>

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QGraphicsScene>
#include <QGraphicsVideoItem>

#include "validsuffix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *);// Rewrite Close Event
    bool checkSuffix(QString);// check suffix

private:
    Ui::MainWindow *ui;

    QMediaPlayer * player = nullptr;
    QAudioOutput * audioOutput = nullptr;
    QGraphicsVideoItem * videoItem = nullptr;
    QGraphicsPixmapItem * pixmapItem = nullptr;
    QGraphicsScene * scene = nullptr;

    QVector<QString> lstSuffix;// Suffix supporting
    QString folderPath = QDir::homePath();// Folder Path choosing, default: C:/Users/xxx
    int currentVolume = 100;// Volume setting, default: 100%
    bool isMuted = false;
    double currentPBR = 1.0; // PlayBackRate setting, default: 1.0

    void initializePlayer();// Initialize paramters of player and audioOutput
    void initializeVideoItem();// Initialize paramters of videoItem
    void initializePixmapItem(bool);// Initialize paramters of pixmapItem

    void funcConnect();// store all the connect(?) statements
    void openAndPlay(QString);// play video/audio

    /* Local Setting & Default Value */
    void saveDefaultValue();// store default setting when you close the ParodicPlayer
    void setDefaultValue();// setting both default volume and default path when exec program
    void setFolderPath(QFileInfo);// setting default path only

    /* Progress & Volume */
    void setProgress(qint64);// set the playback progress
    void UpdatePositon(qint64);// update the slider's displaying
    void setVolume(int);// set the volume
    void UpdatePosVol(int);// update the volume slider's displaying
    void setSoundIcon(float);// set Sound button Icon by the volume
};
#endif // MAINWINDOW_H
