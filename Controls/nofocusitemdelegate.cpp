#include "nofocusitemdelegate.h"

NoFocusItemDelegate::NoFocusItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

void NoFocusItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // 去除焦点状态
    QStyleOptionViewItem customOption = option;
    if ( option.state.testFlag(QStyle::State_HasFocus) )
    {
        customOption.state = option.state ^ QStyle::State_HasFocus;
    }

    QStyledItemDelegate::paint(painter, customOption, index);
}
