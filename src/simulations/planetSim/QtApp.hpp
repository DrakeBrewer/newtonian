#ifndef QTAPP_HPP
#define QTAPP_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QPalette>
#include <QVBoxLayout>
#include <QDebug>
#include <QComboBox>

#include "simConfig.hpp"


class QtApp : public QMainWindow{
    Q_OBJECT //Macro required by QT to allow signals and slots

public:
    /*Constructor for a QtApp. *parent defines a parent widget and nullptr is the default value
    and also indicates that the widget is independent of other widgets*/
    QtApp(QWidget *parent = nullptr);


private slots:
    //Qt uses slots that to handle behavior such as button clicks
    void startApp();

private:
    //Declarations for some basic buttons
    QWidget *centralWidget;
    QVBoxLayout *layout;
    QPushButton *startButton;
    QPushButton *quitButton;

    //simConfigWindow *configWindow;

};


#endif 