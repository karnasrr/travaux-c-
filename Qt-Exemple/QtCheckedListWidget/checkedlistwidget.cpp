#include "checkedlistwidget.h"
#include "ui_checkedlistwidget.h"

CheckedListWidget::CheckedListWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CheckedListWidget)
{
    ui->setupUi(this);
}

CheckedListWidget::~CheckedListWidget()
{
    delete ui;
}
