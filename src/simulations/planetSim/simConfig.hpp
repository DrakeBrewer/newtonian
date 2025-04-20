#ifndef SIMCONFIG_HPP
#define SIMCONFIG_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QPalette>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QListWidget>
#include <QMessageBox>
#include <string>

#include "planets.hpp"
#include "simulation.hpp"


class simConfigWindow: public QWidget{
    Q_OBJECT // Macro required by QT to allow signals and slots

public:
    simConfigWindow(QWidget *parent = nullptr); 
    /*Constructor for a QtApp. *parent defines a parent widget and nullptr is the default value
    and also indicates that the widget is independent of other widgets*/

private slots: //Qt uses slots that to handle behavior such as button clicks
    void checkInputs();

private:
    QPushButton *quitButton;
    QPushButton *startButton;

    QLabel *selectPlanetLabel;
    QLabel *selectObjectLabel;

    QComboBox *planetSelect;
    QComboBox *objectSelect;

    QLineEdit *xInput;
    QLineEdit *yInput;
    QLineEdit *zInput;

    QLineEdit *massInput;
    QLineEdit *initVInput;

    QLineEdit *xPlaneInput;
    QLineEdit *yPlaneInput;
    QLineEdit *zPlaneInput;


    QDoubleValidator *floatValidator;

    QWidget *centerlWidget;
    QVBoxLayout *layout;



};


#endif