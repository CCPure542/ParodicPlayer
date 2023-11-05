#include "classbuttonmouser.h"

ButtonMouseR::ButtonMouseR(QWidget *parent)
    : QToolButton{parent}
{

}

void ButtonMouseR::mousePressEvent(QMouseEvent * ev)
{
    if(ev->buttons() & Qt::RightButton)
    {
        emit signalListJump();
    }
    else
    {
        QToolButton::mousePressEvent(ev);
    }
}
