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
    /* Rewrite - handling key event is not permitted */
    void keyPressEvent(QKeyEvent *);

signals:
    /* Signal - resize */
    void signalResize();
};

#endif // CLASSPPGRAPHICSVIEW_H
