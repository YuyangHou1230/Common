#include "itemwidget.h"

#include <QHBoxLayout>

const int DEFAULT_MAIN_ITEM_HEIGHT = 45;   // 默认的主项高度
const int DEFAULT_SUB_ITEM_HEIGHT  = 35;

ItemWidget::ItemWidget(ItemData data, ItemWidget *parentItem, QWidget *parent)
    : QWidget(parent)
    , m_data(data)
    , m_parentItem(parentItem)
{
    init();
}

void ItemWidget::init()
{
    m_iconLabel = new QLabel();
    m_iconLabel->setFixedSize(30, 30);

    m_contentLabel = new QLabel(m_data.title);

    m_btnOperation = new QPushButton();
    m_btnOperation->setFixedSize(30, 30);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_iconLabel, 0);
    mainLayout->addWidget(m_contentLabel, 1);
    mainLayout->addWidget(m_btnOperation, 0);

    if ( m_parentItem )
    {
        setMinimumHeight(DEFAULT_SUB_ITEM_HEIGHT);
    }
    else
    {
        setMinimumHeight(DEFAULT_MAIN_ITEM_HEIGHT);
    }
}
