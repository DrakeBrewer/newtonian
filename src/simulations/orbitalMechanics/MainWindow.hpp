#pragma once
#include <QMainWindow>
#include "orbitSimulation.hpp"
#include <QLineEdit>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    OrbitSimulation integrateOrbitSim;


    void planetSelected(const QString &planet);
 
    QLabel *moonMassRangeLabel;
};