#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QLabel>
#include <QObject>
#include <QPushButton>
#include <QWidget>

struct ItemData
{
    QString title;
    int     data;
    ItemData()
    {
    }
    ItemData(QString t)
    {
        title = t;
    }
};

class ItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ItemWidget(ItemData data, ItemWidget *parentItem = nullptr, QWidget *parent = nullptr);

signals:

private:
    void init();

private:
    QLabel *     m_iconLabel;
    QLabel *     m_contentLabel;
    QPushButton *m_btnOperation;

    ItemData    m_data;
    ItemWidget *m_parentItem;
};

#endif   // ITEMWIDGET_H
