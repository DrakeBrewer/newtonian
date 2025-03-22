#ifndef QTAPP_HPP
#define QTAPP_HPP

#include <QmainWindow>
#include <QPushButton>
#include <QApplication>
#include <QPalette>

class QtApp : public QMainWindow{
    Q_OBJECT //Macro required by QT to allow signals and slots

public:
    /*Constructor for a QtApp. *parent defines a parent widget and nullptr is the default value
    and also indicates that the widget is independent of other widgets*/
    QtApp(QWidget *parent = nullptr);

private slots:
    //Qt uses slots that to handle behavior such as button clicks
    void runSim();

private:
    //Declarations for some basic buttons
    QPushButton *startButton;
    QPushButton *quitButton;

};


#endif 