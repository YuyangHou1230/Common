#include "colorblock.h"

#include <QMouseEvent>
#include <QPainter>

const int g_HoverOffset = 2;
const int g_margin = 2;

ColorBlock::ColorBlock(QWidget *parent) : QWidget(parent)
{
    m_color = Qt::black;
    m_hasHover = true;
    m_hasHoverBorder = true;

    m_pressed = false;
    m_isEnter = false;

    setToolTip(tr("color: %1").arg(m_color.name()));
}

ColorBlock::ColorBlock(QColor color, QWidget *parent) : QWidget(parent) ,
     m_color(color)
{
    m_hasHover = true;
    m_hasHoverBorder = true;

    m_pressed = false;
    m_isEnter = false;

    setToolTip(tr("color: %1").arg(m_color.name()));
}

void ColorBlock::paintEvent(QPaintEvent *e)
{
    (void)e;
    QPainter painter(this);

    // 绘制阴影

    // 绘制色块
    QRect rec = rect();
    rec = rec.adjusted(g_margin, g_margin, -g_margin, -g_margin);
    int hoverOffset = 0;
    if(m_hasHover && !m_isEnter){
        hoverOffset = g_HoverOffset;
    }
    QRect content = rec.adjusted(hoverOffset, hoverOffset, -hoverOffset, -hoverOffset);

    // 绘制边框
    if(m_hasHover && m_hasHoverBorder && m_isEnter){
        painter.fillRect(rect(), Qt::black);
    }

    painter.fillRect(content, m_color);
}

void ColorBlock::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        m_pressed = true;
    }
}

void ColorBlock::mouseReleaseEvent(QMouseEvent *e)
{
    (void)e;
    if(m_pressed){
        emit clicked();
    }
}

void ColorBlock::enterEvent(QEvent *e)
{
    m_isEnter = true;

    update();

    QWidget::enterEvent(e);
}

void ColorBlock::leaveEvent(QEvent *e)
{
    m_isEnter = false;

    update();

    QWidget::leaveEvent(e);
}

QColor ColorBlock::color() const
{
    return m_color;
}

void ColorBlock::setColor(const QColor &color)
{
    m_color = color;
}

ColorIndicator::ColorIndicator(QWidget *parent) : ColorBlock(parent)
{
    m_hasHover = false;
    m_hasHoverBorder = false;
}
