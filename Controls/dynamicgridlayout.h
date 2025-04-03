#ifndef DYNAMICGRIDLAYOUT_H
#define DYNAMICGRIDLAYOUT_H

#include <QGridLayout>
#include <QMap>
#include <QWidget>

class DynamicGridLayout : public QGridLayout
{
public:
    explicit DynamicGridLayout(QWidget *parent);
    DynamicGridLayout();

    void updateLayout();

    void addWidget(QWidget *widget);

    void setWidgetVisible(int index, bool visible);

    int column() const;
    void setColumn(int column);

private:
    QList<QWidget *> m_widgets;
    QMap<QWidget *, bool> m_visivleMap;
    int m_column;
};

#endif // DYNAMICGRIDLAYOUT_H
