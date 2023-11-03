#include "classppgraphicsview.h"

PPGraphicsView::PPGraphicsView(QWidget *parent)
    : QGraphicsView{parent}
{

}

void PPGraphicsView::resizeEvent(QResizeEvent * ev)
{
    QGraphicsView::resizeEvent(ev);
    emit signalResize();
}
