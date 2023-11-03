#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classppgraphicsview.h"

void MainWindow::funcConnect() {

    /* Size changed - GraphicsView */
    connect(ui->graphicsView,&PPGraphicsView::signalResize,this,[=]()
    {
        if(videoItem == nullptr) return;
        videoItem->setSize(QSize(ui->graphicsView->width(),ui->graphicsView->height()));
        qDebug() << videoItem->boundingRect();
    });

    /* Button - Pause/Play */
    connect(ui->btn_pause,&QToolButton::clicked,this,[=]()
    {
        if(player->isPlaying()) {
            player->pause();
            ui->btn_pause->setIcon(QIcon(":/res/icon_play"));
        }
        else {
            player->play();
            ui->btn_pause->setIcon(QIcon(":/res/icon_pause"));
        }
    });

    /* Button - Stop Playing */
    connect(ui->btn_stop,&QToolButton::clicked,this,[=]()
    {
        player->stop();
    });

    /* Button - Forward/Next */
    connect(ui->btn_next,&QToolButton::clicked,this,[=]()
    {
        setProgress(player->position()/1000+5);
    });

    /* Button - Back/Previous */
    connect(ui->btn_pre,&QToolButton::clicked,this,[=]()
    {
        setProgress(player->position()/1000-5);
    });

    /* Button - Open File and Ready to play */
    connect(ui->btn_open,&QToolButton::clicked,this,[=]()
    {
        QString chooseFilePath = QFileDialog::
            getOpenFileName(this,"Open File",folderPath,getSuffixFilter());
        if(chooseFilePath.isEmpty()) return;// Case in which you click cancel
        setFolderPath(QFileInfo(chooseFilePath));// update default path
        openAndPlay(chooseFilePath);// Sent path to open
    });

    /* Button - Mute and Unmute */
    connect(ui->btn_sound,&QToolButton::clicked,this,[=]()
    {
        if(audioOutput->isMuted()) {
            audioOutput->setMuted(false);
            isMuted = false;
        }
        else {
           audioOutput->setMuted(true);
           isMuted = true;
        }
    });

    /* Button - Choose folder to set PlayList */
    connect(ui->btn_openmult,&QToolButton::clicked,ui->dockWidget,[=]()
    {
        QStringList chooseFilesPath = QFileDialog::
            getOpenFileNames(this,"Open File",folderPath,getSuffixFilter());
        if(chooseFilesPath.isEmpty()) return;// Case in which you click cancel
        setFolderPath(QFileInfo(chooseFilesPath.at(0)));// update default path
        ui->listWidget->chooseAndSet(chooseFilesPath);// Sent path to set PlayList
    });

    /* Button - Show PlayList */
    connect(ui->btn_list,&QToolButton::clicked,ui->dockWidget,[=]()
    {
        if(ui->dockWidget->isHidden()) ui->dockWidget->show();
        else ui->dockWidget->hide();
    });

    /* Slider Progress - when you move it */
    connect(ui->slider_progress,&QSlider::sliderMoved,this,&MainWindow::setProgress);

    /* Slider Progress - when video is playing */
    connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::UpdatePositon);

    /* Slider Volume */
    connect(ui->slider_volume,&QSlider::sliderMoved,this,&MainWindow::setVolume);

    /* Icon Changing - Sound Button */
    connect(audioOutput,&QAudioOutput::mutedChanged,ui->btn_sound,[=](bool isMuted)
    {
        if(isMuted) {
            ui->btn_sound->setIcon(QIcon(":/res/icon_sound"));
        }
        else {
           ui->btn_sound->setIcon(QIcon(":/res/icon_sound_33"));
        }
    });

    /* Icon Changing - Play/Stop Button - when the video starts playing or stops playing */
    connect(player,&QMediaPlayer::playingChanged,this,[=](bool playing)
    {
        if(!playing) ui->btn_pause->setIcon(QIcon(":/res/icon_play"));
        else ui->btn_pause->setIcon(QIcon(":/res/icon_pause"));
    });

    /* Icon Changing - Sound Button */
    connect(audioOutput,&QAudioOutput::volumeChanged,this,&MainWindow::setSoundIcon);

    /* PlayBackRate */
    connect(ui->spinBox_pbr,&QDoubleSpinBox::valueChanged,
        player,&QMediaPlayer::setPlaybackRate);
}
