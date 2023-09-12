#ifndef COLORBLOCK_H
#define COLORBLOCK_H

#include <QWidget>
#include <QColor>

/**
 * @brief The ColorBlock class
 * 颜色块
 */
class ColorBlock : public QWidget
{
    Q_OBJECT
public:
    explicit ColorBlock(QWidget *parent = nullptr);
    ColorBlock(QColor color, QWidget *parent = nullptr);

    QColor color() const;
    void setColor(const QColor &color);

signals:
    void clicked();

protected:
    void paintEvent(QPaintEvent *e) override;

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

    void enterEvent(QEvent *e) override;
    void leaveEvent(QEvent *e) override;

protected:
     QColor m_color;
     bool m_hasHover;
     bool m_hasHoverBorder;

private:


    bool m_pressed;
    bool m_isEnter;

};

class ColorIndicator : public ColorBlock
{
    Q_OBJECT
public:
    ColorIndicator(QWidget *parent = nullptr);
};

#endif // COLORBLOCK_H
