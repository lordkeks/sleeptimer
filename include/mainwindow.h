//
// Created by Christian on 09/05/2025.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

//private slots:
//    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui{};
    QTimer *timer;
    QTime currentTime;
    bool running = false;

    void on_pushButton_clicked();
    void on_timer_tick();

};

#endif //MAINWINDOW_H