#include "secondarylistwidget.h"

#include "itemwidget.h"

SecondaryListWidget::SecondaryListWidget(QWidget *parent)
    : QListWidget(parent)
{
    setThemes(QStringList() << "11"
                            << "22"
                            << "33");
}

void SecondaryListWidget::setThemes(QStringList list)
{

    for ( auto p : list )
    {
        QListWidgetItem *item = new QListWidgetItem();
        addItem(item);

        QSize size = item->sizeHint();
        size.setHeight(45);

        item->setSizeHint(size);

        ItemWidget *widget = new ItemWidget(p);
        setItemWidget(item, widget);
    }
}
