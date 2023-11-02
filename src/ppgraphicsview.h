#ifndef PPGRAPHICSVIEW_H
#define PPGRAPHICSVIEW_H

#include <QGraphicsView>

class PPGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit PPGraphicsView(QWidget *parent = nullptr);

    // Rewrite - used to adjust size
    void resizeEvent(QResizeEvent *);

signals:
    void signalResize();
};

#endif // PPGRAPHICSVIEW_H
