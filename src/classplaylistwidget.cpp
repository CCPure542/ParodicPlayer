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
                ==item->getFileInfo().filePath());});// search
        if (temp!=playlist.end())
        {
            delete item; // found resipitive path so delete
            continue;
        }
        else
        {
            playlist.push_back(item); // add
            this->addItem(item);
        }
    }

    connect(this,&QListWidget::itemDoubleClicked,this,[=](QListWidgetItem * item_para)
    {
        ItemPlay * item = dynamic_cast<ItemPlay *>(item_para);
        qDebug() << this->indexFromItem(item);
        emit signalLoadSource(item->getFileInfo());
    }); // activate connect for my custom doubleClicked signal
}

void PlayListWidget::chooseAndDelete()
{
    /* choose from list */
    if(this->currentItem()==nullptr) return;
    else
    {
        /* Remove element from list<?> - Standard method */
        playlist.erase(std::remove(playlist.begin(), playlist.end(), this->currentItem()), playlist.end());
        /* delete after remove */
        delete this->currentItem();
    }
}

PlayListWidget::~PlayListWidget()
{
    playlist.clear();
}
