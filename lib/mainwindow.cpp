//
// Created by Christian on 09/05/2025.
//
//#define DEBUG
#define OS_WINDOWS
//#define OS_LINUX

#include <iostream>
#include <QTime>
#include <QProcess>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using std::cout, std::endl;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), timer(new QTimer(this)){
    ui->setupUi(this);

    connect(ui->startButton, &QPushButton::released, this, &MainWindow::start_pause);
    connect(ui->addButton, &QPushButton::released, this, &MainWindow::add_time);
    connect(ui->subButton, &QPushButton::released, this, &MainWindow::sub_time);
    connect(timer, &QTimer::timeout, this, &MainWindow::on_timer_tick);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::start_pause() {
    //cout << "button clicked" << endl;
    if (running) { // timer is paused
        ui->startButton->setText("start");
        ui->timeEdit->setEnabled(true);
        ui->addButton->setEnabled(true);
        ui->subButton->setEnabled(true);
        running = false;
        timer->stop();
        cout << "paused" << endl;
    }
    else { // timer is running
        ui->startButton->setText("pause");
        ui->timeEdit->setEnabled(false);
        ui->addButton->setEnabled(false);
        ui->subButton->setEnabled(false);
        running = true;
        timer->start(1000);
        cout << "running" << endl;
    }
}

void MainWindow::on_timer_tick() {
    const QTime timeVal = ui->timeEdit->time();
    if (timeVal <= QTime(0,0,0)){
        timer->stop();
        cout << "shutting down" << endl;
#ifdef OS_WINDOWS
    #ifndef DEBUG
        QProcess::execute("shutdown /s /f /t 0");
    #endif
#elif ifdef OS_LINUX
    #ifdef DEBUG
        QProcess::execute("shutdown now");
    #endif
#endif
        this->close();
    }
    const QTime newTime = timeVal.addSecs(-1);
    ui->timeEdit->setTime(newTime);
    //cout << "tick" << endl;
}

void MainWindow::add_time() const {
    const QTime timeVal = ui->timeEdit->time();
    ui->timeEdit->setTime(timeVal.addSecs(60*10));
}

void MainWindow::sub_time() const {
    const QTime timeVal = ui->timeEdit->time();
    ui->timeEdit->setTime(timeVal.addSecs(-60*10));
}
