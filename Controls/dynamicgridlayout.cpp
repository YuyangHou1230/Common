#include "dynamicgridlayout.h"

DynamicGridLayout::DynamicGridLayout(QWidget *parent) : QGridLayout(parent)
{
    m_column = 2;
}

DynamicGridLayout::DynamicGridLayout() : QGridLayout()
{
     m_column = 2;
}

void DynamicGridLayout::updateLayout()
{
    // 清空当前布局
    QLayoutItem *item;
    while ((item = takeAt(0)) != nullptr) {
        item->widget()->setVisible(false);  // 隐藏控件
    }

    // 重新排列控件
    int nums = m_widgets.size();
    int index = 0;
    for (int i = 0; i < nums; ++i) {
        int row = index / m_column;
        int col = index % m_column;

        if(m_visivleMap[m_widgets[i]])
        {
            m_widgets[i]->setVisible(true);       // 显示控件
            QGridLayout::addWidget(m_widgets[i], row, col);
            index++;
        }
    }
}

void DynamicGridLayout::addWidget(QWidget *widget)
{
    m_widgets.append(widget);
    m_visivleMap[widget] = true;

    updateLayout();
}

void DynamicGridLayout::setWidgetVisible(int index, bool visible)
{
    m_visivleMap[m_widgets[index]] = visible;

    updateLayout();
}

int DynamicGridLayout::column() const
{
    return m_column;
}

void DynamicGridLayout::setColumn(int column)
{
    if(column < 1)
    {
        column = 1;
    }
    m_column = column;

    updateLayout();
}
