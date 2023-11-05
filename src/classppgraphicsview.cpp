#include "classppgraphicsview.h"

PPGraphicsView::PPGraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{

}

void PPGraphicsView::resizeEvent(QResizeEvent * ev)
{
    emit signalResize();
    QGraphicsView::resizeEvent(ev);
}

void PPGraphicsView::keyPressEvent(QKeyEvent * ev)
{
    parent()->parent()->event((QEvent *)ev);
}
