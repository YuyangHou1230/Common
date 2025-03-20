#include "ipedit.h"

#include <QHBoxLayout>
#include <QKeyEvent>
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

IPEdit::IPEdit(QWidget *parent) : QFrame(parent)
{
    init();

    setStyleSheet("IPEdit{border: 1px solid rgb(180, 180, 180);background: white;} IPEdit QLineEdit{border: none; background: transparent;}");
}

bool IPEdit::eventFilter(QObject *watched, QEvent *event)
{
    if(!m_editList.contains(qobject_cast<QLineEdit*>(watched)))
    {
        return false;
    }

    QLineEdit *edit = qobject_cast<QLineEdit*>(watched);

    QKeyEvent *keyEvent = dynamic_cast<QKeyEvent *>(event);
    if(!keyEvent)
    {
        return false;
    }



    if(keyEvent->key() == Qt::Key_Period) // 输入点自动跳到下一个
    {

        if(keyEvent->type() != QEvent::KeyPress)// 只处理按下，不处理弹起，否则会导致处理代码执行两次，后续焦点跳转后下一个控件后仍会收到弹起事件
        {
            return false;
        }

        if(edit != m_editList.last() && keyEvent->key() == Qt::Key_Period && !edit->text().isEmpty())
        {
            keyEvent->accept();
            int index = m_editList.indexOf(edit);
            m_editList.at(index + 1)->setFocus();
            m_editList.at(index + 1)->selectAll();

            return true;
        }

    }
    else if(keyEvent->key() == Qt::Key_Backspace) // 删除时自动向前移动光标
    {
        if(keyEvent->type() != QEvent::KeyPress)// 根据测试，edit删除响应的是press状态，所以只处理按下，不处理弹起，在edit文本变化前判断
        {
            return false;
        }

        if(edit != m_editList.first() && edit->text().isEmpty())
        {
            int index = m_editList.indexOf(edit);
            m_editList.at(index - 1)->setFocus();

            return true;
        }
    }




    return false;
}

QString IPEdit::text()
{
    QString text = QString("%1.%2.%3.%4").arg(m_editList[0]->text()).arg(m_editList[1]->text()).arg(m_editList[2]->text()).arg(m_editList[3]->text());
    return text;
}

void IPEdit::init()
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(0);

    for(int i=0; i < 4; i++)
    {
        if(i > 0)
        {
            QLabel *label = new QLabel();
            label->setText(".");
            layout->addWidget(label, 0);
        }
        QLineEdit *edit = new QLineEdit();
        edit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        edit->setAlignment(Qt::AlignCenter);
        edit->setMaxLength(3);
        QRegularExpression regExp("^([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$");
        QValidator *validator = new QRegularExpressionValidator(regExp, this);
        edit->setValidator(validator);
        layout->addWidget(edit, 1);

        edit->installEventFilter(this);

        m_editList.append(edit);
    }

}
