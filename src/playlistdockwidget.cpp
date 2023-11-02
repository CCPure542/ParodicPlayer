#include "playlistdockwidget.h"

PlayListDockWidget::PlayListDockWidget(QWidget *parent)
    : QDockWidget{parent}
{
    dir = nullptr;
    lstFileInfo = nullptr;
}

void PlayListDockWidget::chooseAndSet(QString path) {
    if(dir!=nullptr) delete dir;
    if(lstFileInfo!=nullptr) delete lstFileInfo;
    dir = new QDir(path);
    QStringList filter = getSuffixFilterDir();
    dir->setNameFilters(filter);
    lstFileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));
    qDebug() << lstFileInfo->count();
    delete dir; dir = nullptr;
    appendPlayList();
}

void PlayListDockWidget::appendPlayList() {
    for(QList<QFileInfo>::Iterator it = lstFileInfo->begin();it!=lstFileInfo->end();it++) {
        playList.push_back(new QFileInfo(*it));
    }
    delete lstFileInfo; lstFileInfo = nullptr;
    qDebug() << playList.count();
    loadPlayList();
}

void PlayListDockWidget::loadPlayList() {

}

PlayListDockWidget::~PlayListDockWidget() {
    playList.clear();
    btnPlayList.clear();
}
