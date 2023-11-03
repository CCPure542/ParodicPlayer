#ifndef CLASSPPGRAPHICSVIEW_H
#define CLASSPPGRAPHICSVIEW_H

#include <QGraphicsView>

class PPGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PPGraphicsView(QWidget *parent = nullptr);

    /* Rewrite - used to adjust size */
    void resizeEvent(QResizeEvent *);

signals:
    void signalResize();
};

#endif // CLASSPPGRAPHICSVIEW_H
