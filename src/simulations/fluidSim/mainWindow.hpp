#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QPalette>
#include <QDebug>


class MainWindow : public QMainWindow{
    Q_OBJECT //Macro required by QT to allow signals and slots

public:
    /*Constructor for a QtApp. *parent defines a parent widget and nullptr is the default value
    and also indicates that the widget is independent of other widgets*/
    MainWindow(QWidget *parent = nullptr);

private slots:
    //Qt uses slots that to handle behavior such as button clicks
    //void startSim();

private:
    //Declarations for some basic buttons
    QPushButton *startButton;
    QPushButton *quitButton;

};


#endif 