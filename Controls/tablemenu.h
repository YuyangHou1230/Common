#ifndef TABLEMENU_H
#define TABLEMENU_H

#include <QTableWidget>

class TableMenu : public QTableWidget
{
    Q_OBJECT
public:
    TableMenu(QWidget *parent = nullptr);

    void setStringList(const QStringList &list, int defaultIndex = 0);

signals:
    void sigRowClicked(int index);
    void sigRowClicked(QString text);
};

#endif   // TABLEMENU_H
