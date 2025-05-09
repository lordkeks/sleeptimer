//
// Created by Christian on 09/05/2025.
//

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->pushButton->setText("start");
    ui->timeEdit->setEnabled(!this->running);
}

MainWindow::~MainWindow() {
    delete ui;
}