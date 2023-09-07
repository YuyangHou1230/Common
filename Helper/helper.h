#ifndef HELPER_H
#define HELPER_H

#include <QString>
#include <QVariant>

namespace Helper {
    // 设置widget属性，并更新样式
    void UpdateStyleSheet(QWidget *widget, char* name, QVariant data);
}


#endif // HELPER_H
