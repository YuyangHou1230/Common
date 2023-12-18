#include "tablemenu.h"

#include "nofocusitemdelegate.h"

#include <QHeaderView>

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
