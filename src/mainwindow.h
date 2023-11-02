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

    /* Public Function */

    // Rewrite Close Event
    void closeEvent(QCloseEvent *);
    // check suffix
    bool checkSuffix(QString);

private:
    Ui::MainWindow *ui;

    /* Private Attributes */

    QMediaPlayer * player = nullptr;
    QAudioOutput * audioOutput = nullptr;
    QGraphicsVideoItem * videoItem = nullptr;
    QGraphicsPixmapItem * pixmapItem = nullptr;
    QGraphicsScene * scene = nullptr;

    // Suffix supporting
    QVector<QString> lstSuffix;
    // Folder Path choosing, default: C:/Users/xxx
    QString folderPath = QDir::homePath();
    // Volume setting, default: 50%
    int currentVolume = 50;
    bool isMuted = false;
    // PlayBackRate setting, default: 1.0
    double currentPBR = 1.0;

    /* Private Function */

    // Initialize paramters of player and audioOutput
    void initializePlayer();
    // Initialize paramters of videoItem
    void initializeVideoItem();
    // Initialize paramters of pixmapItem
    void initializePixmapItem(bool);

    // store all the connect(?) statements
    void funcConnect();
    // play video/audio
    void openAndPlay(QString);

    /* Local Setting & Default Value*/
    // store default setting when you close the ParodicPlayer
    void saveDefaultValue();
    // setting both default volume and default path when exec program
    void setDefaultValue();
    // setting default path only
    void setFolderPath(QFileInfo);

    /* Progress & Volume */
    // set the playback progress
    void setProgress(qint64);
    // update the slider's displaying
    void UpdatePositon(qint64);
    // set the volume
    void setVolume(int);
    // update the volume slider's displaying
    void UpdatePosVol(int);
    // set Sound button Icon by the volume
    void setSoundIcon(float);
};
#endif // MAINWINDOW_H
