#ifndef TABLEMENU_H
#define TABLEMENU_H

#include <QTableWidget>

/**
 * @brief The TableMenu class
 * 基于QTableWidget实现导航菜单类似效果
 */
class TableMenu : public QTableWidget
{
    Q_OBJECT
public:
    TableMenu(QWidget *parent = nullptr);

    void setStringList(const QStringList &list, int defaultIndex = 0);
    void addItem(QString text);

signals:
    void sigRowClicked(int index);
    void sigRowClicked(QString text);

private:
    QStringList m_list;
};

#endif   // TABLEMENU_H
