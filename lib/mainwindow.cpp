//
// Created by Christian on 09/05/2025.
//

#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using std::cout, std::endl;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    //cout << "button clicked" << endl;
    if (this->running) { // timer is paused
        this->ui->pushButton->setText("start");
        this->ui->timeEdit->setEnabled(true);
        this->running = false;
        cout << "paused" << endl;
    }
    else { // timer is running
        this->ui->pushButton->setText("pause");
        this->ui->timeEdit->setEnabled(false);
        this->running = true;
        cout << "running" << endl;
    }
}
