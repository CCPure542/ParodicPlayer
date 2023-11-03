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

void MainWindow::closeEvent(QCloseEvent *)
{
    saveDefaultValue();
}

void MainWindow::openAndPlay(QString chooseFilePath)
{
    QFileInfo fileInfo(chooseFilePath);
    /* check format */
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

bool MainWindow::checkSuffix(QString chooseSuffix)
{
    if(lstSuffix.contains(chooseSuffix.toLower())!=0)
    {
        return true;
    }
    else
    {
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
