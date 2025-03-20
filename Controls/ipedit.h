#ifndef IPEDIT_H
#define IPEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>

class IPEdit : public QFrame
{
    Q_OBJECT
public:
    explicit IPEdit(QWidget *parent = nullptr);

    bool eventFilter(QObject *watched, QEvent *event) override;

    QString text();

signals:
    void editFinshed();

private:
    void init();

private:
    QList<QLineEdit *> m_editList;

};

#endif // IPEDIT_H
