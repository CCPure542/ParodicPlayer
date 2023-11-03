#include "classplaylistwidget.h"

PlayListWidget::PlayListWidget(QWidget *parent)
    : QListWidget{parent}
{

}

void PlayListWidget::chooseAndSet(QStringList path)
{
    QList<QString> lst = path.toList();
    for(QList<QString>::Iterator it = lst.begin();it!=lst.end();it++) {
        ItemPlay * item = new ItemPlay(QFileInfo(*it),this);
        /* check if there is a same path in the list */
        auto temp = std::find_if(playlist.begin(),playlist.end(),
            [&](const ItemPlay * bp){return(bp->getFileInfo().filePath()
                ==item->getFileInfo().filePath());});
        if (temp!=playlist.end())
        {
            delete item; // found same path so delete
            continue;
        }
        else
        {
            playlist.push_back(item); // add
        }
    }
    connect(this,&PlayListWidget::itemDoubleClicked,this,[=](ItemPlay * item)
    {
        emit signalLoadSource(item->getFileInfo());
    }); // activate connect
    qDebug() << lst.count();
}

void PlayListWidget::chooseAndDelete() {
    if(this->currentItem()==nullptr) return;
    else
    {
        delete this->currentItem();
    }
}

PlayListWidget::~PlayListWidget()
{
    playlist.clear();
}
