#include "opacitybutton.h"

OpacityButton::OpacityButton(QWidget *parent) : QPushButton(parent)
{
    m_duration = 1000;
    setIconSize(QSize(80, 80));
    setIcon(QIcon("E:\\QT_PROJECT\\QStackedDemo\\checkedIcon.png"));

    m_pGraphicsOpacityEffect = new QGraphicsOpacityEffect(this);
    m_pGraphicsOpacityEffect->setOpacity(1);
    setGraphicsEffect(m_pGraphicsOpacityEffect);

    m_pNameAnimation = new QPropertyAnimation(m_pGraphicsOpacityEffect,"opacity",this);
    m_pNameAnimation->setEasingCurve(QEasingCurve::Linear);
    m_pNameAnimation->setDuration(m_duration);
    m_pNameAnimation->setStartValue(1);
    m_pNameAnimation->setEndValue(0);

    setStyleSheet("background: transparent; border: 2px solid red; border-radius: 8px;");

//    QGraphicsDropShadowEffect * effect = new QGraphicsDropShadowEffect(this);
//    effect->setColor(Qt::red);
//    effect->setOffset(0,0);
//    effect->setBlurRadius(4);
//    setGraphicsEffect(effect);

}

void OpacityButton::animalHide()
{
    m_pNameAnimation->start();
}

void OpacityButton::show()
{
    if(m_pNameAnimation->state() == QPropertyAnimation::Running)
    {
           m_pNameAnimation->stop();
    }
    m_pGraphicsOpacityEffect->setOpacity(1);
}

void OpacityButton::setAnimationDuration(int milliseconds)
{
    m_duration = milliseconds;
    m_pNameAnimation->setDuration(milliseconds);

}

int OpacityButton::animationDuration() const
{
    return m_duration;
}
