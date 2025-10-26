#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_widget_3_customContextMenuRequested(const QPoint &pos)
{
    QWidget c;

    QVBoxLayout *outerLayout = new QVBoxLayout(this);
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout ->addWidget(new QLabel("Printer"));
    topLayout ->addWidget(new QComboBox());
    outerLayout ->addLayout(topLayout);
}


void MainWindow::on_widget_2_windowIconChanged(const QIcon &icon)
{
    QWidget c;

    QVBoxLayout *outerLayout = new QVBoxLayout(this);
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout ->addWidget(new QLabel("Printer"));
    topLayout ->addWidget(new QComboBox());
    outerLayout ->addLayout(topLayout);
}


void MainWindow::on_widget_2_windowTitleChanged(const QString &title)
{

}


void MainWindow::on_MainWindow_windowTitleChanged(const QString &title)
{
    QWidget c;

    QVBoxLayout *outerLayout = new QVBoxLayout(this);
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout ->addWidget(new QLabel("Printer"));
    topLayout ->addWidget(new QComboBox());
    outerLayout ->addLayout(topLayout);
}


void MainWindow::on_MainWindow_toolButtonStyleChanged(const Qt::ToolButtonStyle &toolButtonStyle)
{
    QWidget c;

    QVBoxLayout *outerLayout = new QVBoxLayout(this);
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout ->addWidget(new QLabel("Printer"));
    topLayout ->addWidget(new QComboBox());
    outerLayout ->addLayout(topLayout);
}

