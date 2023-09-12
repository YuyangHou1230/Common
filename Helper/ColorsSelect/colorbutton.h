#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include "colorblock.h"
#include "colormenu.h"

class ColorButton : public QFrame
{
    Q_OBJECT
public:
    explicit ColorButton(QWidget *parent = nullptr);

signals:

private:
    QPushButton *btnEdit;
    ColorIndicator *colorLabel;

    ColorMenu *menu;
};

#endif // COLORBUTTON_H
