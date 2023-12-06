#include "helper.h"

#include <QStyle>
#include <QWidget>

namespace Helper
{

void UpdateStyleSheet(QWidget *widget, char *name, QVariant value)
{
    widget->setProperty(name, value);
    widget->style()->unpolish(widget);
    widget->style()->polish(widget);
}

void ClearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ( (item = layout->takeAt(0)) != nullptr )
    {
        QWidget *widget = item->widget();
        if ( widget )
        {
            widget->deleteLater();
        }
        else
        {
            QLayout *sublayout = item->layout();
            if ( sublayout )
            {
                ClearLayout(sublayout);
            }
        }
        delete item;
    }
}

void ClearWidgetLayout(QWidget *widget)
{
    QLayout *layout = widget->layout();
    if ( layout )
    {
        ClearLayout(layout);
        delete layout;
        layout = nullptr;
    }

    widget->setLayout(nullptr);
}

}   // namespace Helper
