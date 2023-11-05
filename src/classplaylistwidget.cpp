#include "classplaylistwidget.h"

PlayListWidget::PlayListWidget(QWidget *parent)
    : QListWidget{parent}
{
    connect(this,&PlayListWidget::signalJumpPlay,this,[=](bool flag)
    {
        /*  "Out of range" and "empty list" are needed to be checked  */
        if(this->count()==0) return;
        if(this->currentRow()<0 || this->currentRow()>=this->count())
            this->setCurrentRow(0);
        /* true: next; false: previous */
        /* calculate the next/pre index (Support Loop) */
        if(flag)
        {
            int nextRow = (this->currentRow() + 1) % this->count();
            this->setCurrentRow(nextRow);
            emit itemDoubleClicked(this->currentItem());
        }
        else
        {
            int preRow = (this->currentRow() - 1);
            if(preRow<0)
                this->setCurrentRow(this->count()-1);
            else
                this->setCurrentRow(preRow);
            emit itemDoubleClicked(this->currentItem());
        }
    });
}

void PlayListWidget::keyPressEvent(QKeyEvent * ev)
{
    parent()->parent()->event((QEvent *)ev);
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
            if(this->currentRow()<0)
                this->setCurrentRow(0);// choosing state
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
