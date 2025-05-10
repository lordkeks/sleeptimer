//
// Created by Christian on 09/05/2025.
//

#include <iostream>
#include <QTime>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using std::cout, std::endl;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), timer(new QTimer(this)){
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::on_pushButton_clicked);
    connect(timer, &QTimer::timeout, this, &MainWindow::on_timer_tick);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    //cout << "button clicked" << endl;
    if (running) { // timer is paused
        ui->pushButton->setText("start");
        ui->timeEdit->setEnabled(true);
        running = false;
        timer->stop();
        cout << "paused" << endl;
    }
    else { // timer is running
        ui->pushButton->setText("pause");
        ui->timeEdit->setEnabled(false);
        running = true;
        timer->start(1000);
        cout << "running" << endl;
    }
}

void MainWindow::on_timer_tick() {
    QTime timeVal = ui->timeEdit->time();
    if (timeVal <= QTime(0,0,0)){
        timer->stop();
        cout << "shutting down" << endl;
        return;
    }
    QTime newTime = timeVal.addSecs(-1);
    ui->timeEdit->setTime(newTime);
    //cout << "tick" << endl;
}
