#include "controltest.h"
#include "ui_controltest.h"

ControlTest::ControlTest(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ControlTest)
{
    ui->setupUi(this);
}

ControlTest::~ControlTest()
{
    delete ui;
}

