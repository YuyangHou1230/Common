#include "searchlineedit.h"

#include <QAction>
#include <QDebug>
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QPushButton>
#include <QTimer>
#include <QToolButton>
#include <QToolTip>
#include <QWidgetAction>
QLabel *label;
class CustomTooltip : public QDialog
{
public:
    CustomTooltip(const QString &text = "", QWidget *parent = nullptr)
        : QDialog(parent)
    {
        setWindowFlags(Qt::ToolTip | Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        setStyleSheet("QDialog { background-color: #3498db; border: 1px solid #2980b9; color: white; }");
        label = new QLabel(text, this);
        label->setAlignment(Qt::AlignCenter);

        QHBoxLayout *layout = new QHBoxLayout(this);
        layout->addWidget(label);

        QTimer::singleShot(10000, this, &QWidget::hide);   // 隐藏时间为10秒
    }

    void showText(QPoint pos, QString text)
    {
        label->setText(text);
        move(pos);
        show();
    }
};
SearchLineEdit::SearchLineEdit(QWidget *parent)
{

    // 通过QAction的方式为QLineEdit添加图标
    QWidgetAction *widgetAction = new QWidgetAction(this);
    QToolButton *  btn          = new QToolButton();
    //    btn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn->setIconSize(QSize(50, 50));
    btn->setIcon(QIcon("E:\\QT_PROJECT\\Common\\Controls\\Lineedit\\big_search_icon.png"));

    //    btn->setText("搜索");
    //    btn->setMinimumSize(30, 30);

    //    setStyleSheet("QToolButton { border: none; padding: 0; }"
    //                  "QToolButton::icon { width: 50px; height: 50px; }");

    widgetAction->setDefaultWidget(btn);
    addAction(widgetAction, QLineEdit::TrailingPosition);

    //    addAction(QIcon("E:\\QT_PROJECT\\Common\\Controls\\Lineedit\\search_icon.png"), QLineEdit::LeadingPosition);
    addAction(QIcon("E:\\QT_PROJECT\\Common\\Controls\\Lineedit\\big_search_icon.png"), QLineEdit::LeadingPosition);

    qDebug() << "" << textMargins().right();

    //    setToolTip("范围为10-20");

    CustomTooltip *tooltip = new CustomTooltip("范围为10-20");

    connect(btn, &QToolButton::clicked, this, [=]() {
        QPoint p = mapToGlobal(QPoint(0, -20));
        qDebug() << p;
        QToolTip::showText(p, "范围为10-20");
        tooltip->showText(p, "范围为10-20");
    });

    connect(this, &SearchLineEdit::focusIn, this, [=]() {
        QPoint p = mapToGlobal(QPoint(0, -20));
        qDebug() << p;
        if ( tooltip->isHidden() )
        {
            tooltip->showText(p, "范围为10-20");
        }
    });

    connect(this, &SearchLineEdit::textChanged, this, [=]() {
        if ( hasFocus() && tooltip->isHidden() )
        {
            QPoint p = mapToGlobal(QPoint(0, -20));
            qDebug() << p;
            tooltip->show();
        }
    });
    connect(this, &SearchLineEdit::focusOut, this, [=]() {
        //        QToolTip::hideText();
        tooltip->hide();
    });
}

void SearchLineEdit::focusInEvent(QFocusEvent *e)
{
    emit focusIn();

    QLineEdit::focusInEvent(e);
}

void SearchLineEdit::focusOutEvent(QFocusEvent *e)
{
    emit focusOut();

    QLineEdit::focusOutEvent(e);
}
