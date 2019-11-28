#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dialog.h"
#include"cad.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog d;
    d.setModal(true);
    d.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    cad c;
    c.setModal(true);
    c.exec();
}
