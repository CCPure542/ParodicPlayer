#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QScreen * screen = QGuiApplication::primaryScreen();
    QRect rect = screen->availableGeometry();
    this->resize(rect.size());
    this->resize(QSize(width()*0.75,height()*0.75));
    ui->dockWidget->hide();

    /* Supporting suffix */
    setSupportSuffix(lstSuffix);
    /* Initialize paramters of player */
    initializePlayer();
    /* Default setting (path & volumn) from local file */
    setDefaultValue();
    /* Activate signals/slots */
    funcConnect();
}

void MainWindow::closeEvent(QCloseEvent *) {
    saveDefaultValue();
}

void MainWindow::setProgress(qint64 pos) {
    player->setPosition(pos*1000);
    ui->timeEdit_position->setTime(QTime(0,0,0,0).addMSecs(pos*1000));
}

void MainWindow::UpdatePositon(qint64 pos) {
    ui->slider_progress->setMaximum(player->duration() / 1000);
    ui->slider_progress->setValue(pos / 1000);
    ui->timeEdit_position->setTime(QTime(0,0,0,0).addMSecs(pos));
}

void MainWindow::setVolume(int pos) {
    currentVolume = pos;
    audioOutput->setVolume((float)currentVolume * 0.01f);
}

void MainWindow::UpdatePosVol(int pos) {
    ui->slider_volume->setMaximum(100);
    ui->slider_volume->setValue(pos);
}

void MainWindow::setSoundIcon(float volFloat) {
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

void MainWindow::openAndPlay(QString chooseFilePath) {
    QFileInfo fileInfo(chooseFilePath);
    /* change default choosing folder path */
    setFolderPath(fileInfo);
    if(!checkSuffix(fileInfo.suffix())) return;
    /* load file and execute playing */
    player->setSource(QUrl::fromLocalFile(chooseFilePath));
    player->play();
    player->setPlaybackRate(ui->spinBox_pbr->value());
    /* UI */
    ui->menu_FileName->setTitle(fileInfo.fileName());
    ui->menu_Format->setTitle(fileInfo.suffix());
    ui->timeEdit_duration->setTime(QTime(0,0,0,0).addMSecs(player->duration()));
    /* Displaying Policy according the file type */
    if(player->hasVideo()) {
        initializeVideoItem();
    } else {
        initializePixmapItem(true);
    }
}

bool MainWindow::checkSuffix(QString chooseSuffix) {
    if(lstSuffix.contains(chooseSuffix)!=0) {
        return true;
    }
    else {
        QString strInfo("ParodicPlayer only support: ");
        strInfo+=getSupportSuffix(lstSuffix);
        QMessageBox::information(this,"Note",strInfo,QMessageBox::Ok);
        return false;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    scene->clear();
}
