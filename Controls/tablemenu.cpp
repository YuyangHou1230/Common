#include "tablemenu.h"

#include "nofocusitemdelegate.h"

#include <QHeaderView>
#include <QDebug>

TableMenu::TableMenu(QWidget *parent)
    : QTableWidget(parent)
{

    verticalHeader()->hide();
    horizontalHeader()->hide();

    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    setSelectionBehavior(QAbstractItemView::SelectRows);    // 行选择
    setSelectionMode(QAbstractItemView::SingleSelection);   // 单个选中
    setEditTriggers(QAbstractItemView::NoEditTriggers);     // 不可编辑
    setShowGrid(true);


    setItemDelegate(new NoFocusItemDelegate);   // 自定义无交点代理

    connect(this, &TableMenu::currentItemChanged, this, [=](QTableWidgetItem *item)
    {
        if(item != nullptr)
        {
            qDebug() << item->text() << item->row();
        }

        emit sigRowClicked(item->row());
        emit sigRowClicked(item->text());
    });

    // 设置单元格边框和表格网格线样式
    QString style = R"(
            QTableWidget {
                border: 1px none #00FF00; /* 表格边框样式，绿色边框 */
                gridline-color: #0000FF; /* 表格网格线颜色，蓝色网格线 */
            }

            QTableWidget::item {
                border: 1px solid #FF0000; /* 单元格边框样式，红色边框 */
            }
            QTableWidget::item:selected {
                background: blue;
                border: 1px solid #FF0000; /* 单元格边框样式，红色边框 */
            }
        )";
//    setStyleSheet(style);
}

void TableMenu::setStringList(const QStringList &list, int defaultIndex)
{
    setColumnCount(1);
    setRowCount(list.size());

    for ( int i = 0; i < list.size(); i++ )
    {
        model()->setData(model()->index(i, 0), list[i], Qt::DisplayRole);
        model()->setData(model()->index(i, 0), Qt::AlignCenter, Qt::TextAlignmentRole);
    }

    if ( list.size() > 0 && defaultIndex < list.size() )
    {
        selectRow(defaultIndex);
    }
}
