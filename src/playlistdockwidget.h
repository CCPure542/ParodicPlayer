#ifndef PLAYLISTDOCKWIDGET_H
#define PLAYLISTDOCKWIDGET_H

#include <QDockWidget>
#include <QPushButton>
#include <QDir>
#include "validsuffix.h"
class PlayListDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    explicit PlayListDockWidget(QWidget *parent = nullptr);
    ~PlayListDockWidget();
    /* Public Function */

    /* receive path to set list */
    void chooseAndSet(QString);

private:

    /* Private Attributes */

    /* Play List */
    QList<QPushButton *> btnPlayList;
    QList<QFileInfo *> playList;
    /* Used to Receive info of choosing folder */
    QDir * dir = nullptr;
    QList<QFileInfo> * lstFileInfo = nullptr;

    /* Private Function */
    void appendPlayList();
    void loadPlayList();

signals:

};

#endif // PLAYLISTDOCKWIDGET_H
