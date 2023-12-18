#ifndef NOFOCUSITEMDELEGATE_H
#define NOFOCUSITEMDELEGATE_H

#include <QStyledItemDelegate>

/**
 * @brief The NoFocusItemDelegate class
 * QTableView焦点去除代理类， 重新paint函数过滤焦点状态实现
 */
class NoFocusItemDelegate : public QStyledItemDelegate
{
public:
    NoFocusItemDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif   // NOFOCUSITEMDELEGATE_H
