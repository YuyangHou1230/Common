#ifndef OPACITYBUTTON_H
#define OPACITYBUTTON_H

#include <QPushButton>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

/**
 * @brief The OpacityButton class
 * 动画透明按钮类，按钮显示后会渐渐透明消失
 */
class OpacityButton : public QPushButton
{
    Q_OBJECT
public:
    OpacityButton(QWidget *parent = nullptr);

    // 动画隐藏
    void animalHide();
    // 显示 覆盖基类的show函数
    void show();
    // 设置动画事件
    void setAnimationDuration(int milliseconds);

    int animationDuration() const;

private:
    QGraphicsOpacityEffect *m_pGraphicsOpacityEffect;
    QPropertyAnimation *m_pNameAnimation;

    int m_duration;
};

#endif // OPACITYBUTTON_H
