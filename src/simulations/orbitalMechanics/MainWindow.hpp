#pragma once
#include <QMainWindow>
#include "orbitSimulation.hpp"
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include <QElapsedTimer>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    OrbitSimulation integrateOrbitSim;

    void planetSelected(const QString &planet);
 
    QLabel *moonMassRangeLabel;
    QLabel *moonMassDefaultLabel;
    QLabel *moonVelocityDefaultLabel;
    QLabel *planetDistanceDefaultLabel;

    // For showing the live orbital data
    QLabel *orbitCountLabel;
    QLabel *xCoordLabel;
    QLabel *yCoordLabel;
    QTimer *simTimer;
    QTimer *stopwatchTimer;
    QLabel *stopwatchLabel;
    QElapsedTimer simTimeElapsed;
    QPushButton *startBtn;
    QPushButton *stopBtn;

    int timeInterval = 1000; // [ms]
    int timeScalar = 59000; // compress the moons orbit to 40s
    void updateSimulation();
    void startSimulation();
    void stopSimulation();
};