#include "controltest.h"
#include "ui_controltest.h"

ControlTest::ControlTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ControlTest)
{
    ui->setupUi(this);

    ui->tableWidget->setStringList(QStringList() << "功能1"
                                                 << "功能2"
                                                 << "功能3"
                                                 << "功能4"
                                                 << "功能5"
                                                 << "功能6");
}

ControlTest::~ControlTest()
{
    delete ui;
}
