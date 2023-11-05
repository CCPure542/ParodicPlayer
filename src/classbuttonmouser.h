#ifndef BUTTONMOUSER_H
#define BUTTONMOUSER_H

#include <QToolButton>
#include <QMouseEvent>

class ButtonMouseR : public QToolButton
{
    Q_OBJECT
public:
    explicit ButtonMouseR(QWidget *parent = nullptr);
    /* Receive Right Mouse input */
    void mousePressEvent(QMouseEvent *);
signals:
    /* jump to next or previous one in the list */
    void signalListJump();
};

#endif // BUTTONMOUSER_H
