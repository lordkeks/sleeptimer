//
// Created by Christian on 09/05/2025.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    bool running = false;
    void on_pushButton_clicked();
};

#endif //MAINWINDOW_H