#include "helper.h"

#include <QWidget>
#include <QStyle>


namespace Helper {

    void UpdateStyleSheet(QWidget *widget, char* name, QVariant value)
    {
        widget->setProperty(name, value);
        widget->style()->unpolish(widget);
        widget->style()->polish(widget);
    }


}
