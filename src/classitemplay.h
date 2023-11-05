#ifndef CLASSITEMPLAY_H
#define CLASSITEMPLAY_H

#include <QListWidgetItem>
#include <QFileInfo>
#include <QMouseEvent>

class ItemPlay : public QListWidgetItem
{
public:
    /* QFileInfo is needed */
    explicit ItemPlay(QFileInfo fileInfo,QListWidget *parent = nullptr);
    ~ItemPlay();
    /* Get file info */
    const QFileInfo & getFileInfo() const;
private:
    /* Main Attribute */
    QFileInfo fileInfo;
};

#endif // CLASSITEMPLAY_H
