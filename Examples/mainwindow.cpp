#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tablemenu.h"

#include "ColorsSelect/colorbutton.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->addItem("添加项");
}
