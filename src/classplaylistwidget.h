#ifndef CLASSPLAYLISTWIDGET_H
#define CLASSPLAYLISTWIDGET_H

#include <QListWidget>
#include <QFileInfo>
#include "classitemplay.h"
#include "validsuffix.h"

class PlayListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit PlayListWidget(QWidget *parent = nullptr);
    ~PlayListWidget();
    /* Rewrite - handling key event is not permitted */
    void keyPressEvent(QKeyEvent *);
    /* Function for receive paths to set list */
    void chooseAndSet(QStringList);
    /* Function as slot for delete */
    void chooseAndDelete();
private:
    /* Play List */
    QList<ItemPlay *> playlist;

signals:
    /* sent to mainWindow and play */
    void signalLoadSource(QFileInfo);
    /* Receive jumping order */
    void signalJumpPlay(bool);
};

#endif // CLASSPLAYLISTWIDGET_H
