#ifndef SECONDARYLISTWIDGET_H
#define SECONDARYLISTWIDGET_H

#include <QListWidget>

class SecondaryListWidget : public QListWidget
{
public:
    SecondaryListWidget(QWidget *parent = nullptr);

    void setThemes(QStringList list);
};

#endif   // SECONDARYLISTWIDGET_H
