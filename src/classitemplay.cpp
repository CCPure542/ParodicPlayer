#include "classitemplay.h"

ItemPlay::ItemPlay(QFileInfo fileInfo,QListWidget *parent)
    : QListWidgetItem{parent}
{
    this->fileInfo = fileInfo;
    setText(fileInfo.fileName());
}

const QFileInfo & ItemPlay::getFileInfo() const
{
    return this->fileInfo;
}
