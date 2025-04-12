#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QPalette>
#include <QDebug>


class MainWindow : public QMainWindow{
    Q_OBJECT // Macro required by QT to allow signals and slots but still put if not needed

public:
    // Constructor for a MainWindow. 
    // *parent defines a parent widget and nullptr is the default value
    MainWindow(QWidget *parent = nullptr);

private slots:
    // Qt uses slots that to handle behavior such as button click
    //void startSim(); //Need to implement my functions to work with Qt

private:
    // Declarations for some basic buttons
    QPushButton *startButton;
    QPushButton *quitButton;
};

#endif 