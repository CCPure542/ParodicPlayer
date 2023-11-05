#include "classbuttonmouser.h"

ButtonMouseR::ButtonMouseR(QWidget *parent)
    : QToolButton{parent}
{

}

void ButtonMouseR::mousePressEvent(QMouseEvent * ev)
{
    if(ev->buttons() & Qt::RightButton)
    {
        emit signalListJumpPlay();
    }
    else
    {
        QToolButton::mousePressEvent(ev);
    }
}
