#ifndef COLORMENU_H
#define COLORMENU_H

#include "colorblock.h"

#include <QDialog>

class ColorMenu : public QDialog
{
    Q_OBJECT
public:
    explicit ColorMenu(QWidget *parent = nullptr);

signals:
    void selected(QColor color);

private:
    QList<ColorBlock *> m_blocks; //色块list

};

#endif // COLORMENU_H
