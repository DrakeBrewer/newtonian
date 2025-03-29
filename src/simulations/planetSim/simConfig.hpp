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
#include "planets.hpp"


class simConfigWindow: public QWidget{
    Q_OBJECT

public:
    simConfigWindow(QWidget *parent = nullptr);

private slots:
    void startSim();

private:
    QPushButton *quitButton;
    QPushButton *startButton;

    QLabel *selectPlanetLabel;

    QVBoxLayout *layout;

    QRadioButton *earthRadio;
    QRadioButton *moonRadio;
    QRadioButton *mercuryRadio;
    QRadioButton *venusRadio;
    QRadioButton *marsRadio;
    QRadioButton *jupiterRadio;
    QRadioButton *saturnRadio;
    QRadioButton *uranusRadio;
    QRadioButton *neptuneRadio;

    QLineEdit *objectInput;

    QLineEdit *xInput;
    QLineEdit *yInput;
    QLineEdit *zInput;

    QLineEdit *massInput;
    QLineEdit *initVInput;








};


#endif