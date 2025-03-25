#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tablemenu.h"

#include "ColorsSelect/colorbutton.h"

#include "messagequeue.h"
#include <QDebug>
#include <QTimer>

#define QStringMsgQueue MessageQueue<QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList list;
    for ( int i = 0; i < 6; i++ )
    {
        list.append(QString("按钮%1").arg(i + 1));
    }

    ui->tableWidget->setStringList(list);

    ColorButton *btn = new ColorButton(this);

    QStringMsgQueue *queue = new QStringMsgQueue;
    queue->setCallback([](QString msg){qDebug() << msg; });
    queue->start();

    QTimer *timer;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [queue](){queue->addMessage("push msg");});
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->addItem("添加项");
}
