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


class simConfigWindow: public QWidget{
    Q_OBJECT

public:
    simConfigWindow(QWidget *parent = nullptr);

private slots:
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