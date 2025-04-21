#include "MainWindow.hpp"
#include <QApplication>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <string>
#include <QTimer>
#include <QString>
#include <QPushButton>
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Orbital Mechanics Simulator");
    resize(1200,800);

    // Central widget, vertical and horizontal layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Planet Selection Dropdown -------------------------------------------------------------
    QVBoxLayout *dropdownLayout = new QVBoxLayout();

    QLabel *planetLabel = new QLabel("Planet Selection", centralWidget);
    planetLabel->setStyleSheet("font-size: 16pt; font-weight: bold");
    dropdownLayout->addWidget(planetLabel);

    // From this dropdown of planets in the Solar System, the user can select a planet
    QComboBox *planetDropdown = new QComboBox(centralWidget);
    planetDropdown->setMinimumWidth(87);
    planetDropdown->setStyleSheet("QComboBox{ font-size: 20pt; font-weight: bold; }");

    planetDropdown->addItem("Mercury");
    planetDropdown->addItem("Venus");
    planetDropdown->addItem("Earth");
    planetDropdown->addItem("Mars");
    planetDropdown->addItem("Jupiter");
    planetDropdown->addItem("Saturn");
    planetDropdown->addItem("Uranus");
    planetDropdown->addItem("Neptune");
    planetDropdown->setCurrentIndex(2);

    connect(planetDropdown, &QComboBox::currentTextChanged, this, &MainWindow::planetSelected);

    dropdownLayout->addWidget(planetDropdown, 0, Qt::AlignLeft);
    
    mainLayout->addLayout(dropdownLayout);
    mainLayout->addSpacing(21);

    // Setting the Moon Mass -----------------------------------------------------------------
    // Moon Mass Label
    QLabel *moonMassLabel = new QLabel("Set Moon Mass [kg]", centralWidget);
    moonMassLabel->setStyleSheet("font-size: 16pt; font-weight: bold;");
    mainLayout->addWidget(moonMassLabel);

    // Show the valid moon mass range
    moonMassRangeLabel = new QLabel(centralWidget);
    moonMassRangeLabel->setStyleSheet("font-size: 12pt;");
    double minMoonMass = integrateOrbitSim.getMinMoonMass();
    double maxMoonMass = integrateOrbitSim.getMaxMoonMass();
    moonMassRangeLabel->setText(QString("Valid Moon Mass Range: %1 [kg] to %2 [kg]").arg(minMoonMass).arg(maxMoonMass));
    mainLayout->addWidget(moonMassRangeLabel, 0, Qt::AlignLeft);

    // Show the default moon mass
    moonMassDefaultLabel = new QLabel(centralWidget);
    moonMassDefaultLabel->setStyleSheet("font-size:12pt;");
    moonMassDefaultLabel->setText(
    QString("Default: %1 [kg]").arg(integrateOrbitSim.orbitSim.moonMass, 0, 'e', 3));
    mainLayout->addWidget(moonMassDefaultLabel, 0, Qt::AlignLeft);

    // Moon Mass Input Field
    QVBoxLayout *moonMassInputLayout = new QVBoxLayout();
    QLineEdit *moonMassInput = new QLineEdit(centralWidget);
    moonMassInput->setPlaceholderText("Enter in Scientific Notation then press ENTER...");
    moonMassInput->setStyleSheet("font-size: 12pt;");
    moonMassInput->setFixedWidth(360);
    moonMassInputLayout->addWidget(moonMassInput);
    mainLayout->addLayout(moonMassInputLayout);

    connect(moonMassInput, &QLineEdit::returnPressed, this, [=](){
        bool isValid;
        double userMoonMass = moonMassInput->text().toDouble(&isValid);
        if(!isValid){
            qDebug() << "<ERROR: Enter a number>";
            return;
        }

        if(!integrateOrbitSim.isValidMoonMass(userMoonMass)){
            qDebug() << "<ERROR: Enter a valid moon mass>";
            return;
        }

        integrateOrbitSim.orbitSim.moonMass = userMoonMass;
        qDebug() << "<Updated Moon Mass: " << userMoonMass << "[kg]>";
    });
    mainLayout->addSpacing(21);

    // Update Moon Velocity ------------------------------------------------------------------
    QLabel *updateVelocityLabel = new QLabel("Update Moon Velocity [m/s]", centralWidget);
    updateVelocityLabel->setStyleSheet("font-size: 16pt; font-weight: bold;");
    mainLayout->addWidget(updateVelocityLabel);
    
    // Show default moon velocity
    moonVelocityDefaultLabel = new QLabel(centralWidget);
    moonVelocityDefaultLabel->setStyleSheet("font-size:12pt;");
    moonVelocityDefaultLabel->setText(
    QString("Default: %1 [m/s]").arg(integrateOrbitSim.orbitSim.moonVelocity));
    mainLayout->addWidget(moonVelocityDefaultLabel, 0, Qt::AlignLeft);

    // Moon velocity input
    QVBoxLayout *moonVelocityInputLayout = new QVBoxLayout();
    QLineEdit *moonVelocityInput = new QLineEdit(centralWidget);
    moonVelocityInput->setPlaceholderText("Enter moon velocity [m/s] and press ENTER...");
    moonVelocityInput->setStyleSheet("font-size: 12pt;");
    moonVelocityInput->setFixedWidth(360);
    moonVelocityInputLayout->addWidget(moonVelocityInput);
    mainLayout->addLayout(moonVelocityInputLayout);

    connect(moonVelocityInput, &QLineEdit::returnPressed, this, [=]() {
        bool isValid;
        double userVelocity = moonVelocityInput->text().toDouble(&isValid);
        if (!isValid) {
            qDebug() << "<ERROR: Enter a number>";
            return;
        }

        integrateOrbitSim.orbitSim.updateMoonVelocity(userVelocity);
        qDebug() << "<Updated moon velocity: " << userVelocity << " [m/s]>";
    });
    mainLayout->addSpacing(21);

    // Update Planet to Moon Distance --------------------------------------------------------
    QLabel *updateDistanceLabel = new QLabel("Update Planet to Moon Distance [m]", centralWidget);
    updateDistanceLabel->setStyleSheet("font-size: 16pt; font-weight: bold;");
    mainLayout->addWidget(updateDistanceLabel);

    // Default planet-moon distance
    planetDistanceDefaultLabel = new QLabel(centralWidget);
    planetDistanceDefaultLabel->setStyleSheet("font-size:12pt;");
    planetDistanceDefaultLabel->setText(
    QString("Default: %1 [m]").arg(integrateOrbitSim.orbitSim.planetMoonDistance, 0, 'e', 3));
    mainLayout->addWidget(planetDistanceDefaultLabel, 0, Qt::AlignLeft);

    // Planet-moon distance input
    QVBoxLayout *distanceInputLayout = new QVBoxLayout();
    QLineEdit *distanceInput = new QLineEdit(centralWidget);
    distanceInput->setPlaceholderText("Enter planet-moon distance [m] and press ENTER...");
    distanceInput->setStyleSheet("font-size: 12pt;");
    distanceInput->setFixedWidth(360);
    distanceInputLayout->addWidget(distanceInput);
    mainLayout->addLayout(distanceInputLayout);

    connect(distanceInput, &QLineEdit::returnPressed, this, [=]() {
        bool isValid;
        double userDistance = distanceInput->text().toDouble(&isValid);
        if (!isValid) {
            qDebug() << "<ERROR: Enter a number>";
            return;
        }

        integrateOrbitSim.orbitSim.updatePlanetMoonDistance(userDistance);
        qDebug() << "<Updated planet-moon distance: " << userDistance << " [m]>";
    });
    mainLayout->addStretch();

    // Live coordinates display and orbit counter --------------------------------------------
    orbitCountLabel = new QLabel("Orbits Complete: 0", centralWidget);
    orbitCountLabel->setStyleSheet("font-size: 16pt; font-weight: bold; color: #123456");
    stopwatchLabel = new QLabel("Time: 00:00:000", centralWidget);
    stopwatchLabel->setStyleSheet("font-size: 12pt; color: #0B6623");
    xCoordLabel = new QLabel("X: 0 [m]", centralWidget);
    xCoordLabel->setStyleSheet("font-size: 12pt; color: #282928");
    yCoordLabel = new QLabel("Y: 0 [m]", centralWidget);
    yCoordLabel->setStyleSheet("font-size: 12pt; color: #282928");
    

    QVBoxLayout *simLayout = new QVBoxLayout();
    simLayout->addWidget(orbitCountLabel);
    simLayout->addWidget(stopwatchLabel);
    simLayout->addWidget(xCoordLabel);
    simLayout->addWidget(yCoordLabel);
    mainLayout->addLayout(simLayout);

    mainLayout->addStretch();

    startBtn = new QPushButton("Start Simulation", centralWidget);
    stopBtn = new QPushButton("Stop Simulation", centralWidget);
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(startBtn);
    btnLayout->addWidget(stopBtn);
    mainLayout->addLayout(btnLayout);

    simTimer = new QTimer(this);
    connect(simTimer, &QTimer::timeout, this, &MainWindow::updateSimulation);
    stopwatchTimer = new QTimer(this);
    connect(stopwatchTimer, &QTimer::timeout, this, [=](){
        long long elapsedTime = simTimeElapsed.elapsed();
        int min = (int)(elapsedTime / 60000);
        int sec = (int)((elapsedTime % 60000) / 1000);
        int ms = (int)(elapsedTime % 1000);
    
        stopwatchLabel->setText(QString("Elapsed Time: %1.%2.%3")
        .arg(min,2,10,QChar('0')).arg(sec,2,10,QChar('0')).arg(ms,3,10,QChar('0')));
    });
    connect(startBtn, &QPushButton::clicked, this, &MainWindow::startSimulation);
    connect(stopBtn, &QPushButton::clicked, this, &MainWindow::stopSimulation);
    stopBtn->setEnabled(false);
}

// Method for updating the live coords of the moon and orbit counter
void MainWindow::updateSimulation(){
    integrateOrbitSim.orbitSim.updateMoonOrbitalPosition(timeInterval, timeScalar);

    double x = integrateOrbitSim.orbitSim.posX;
    double y = integrateOrbitSim.orbitSim.posY;
    int orbitCount = integrateOrbitSim.orbitSim.orbitCounter;

    orbitCountLabel->setText(QString("Orbit Count: %1").arg(orbitCount));
    xCoordLabel->setText(QString("X: %1 [m]").arg(x, 0, 'e', 5));
    yCoordLabel->setText(QString("Y: %1 [m]").arg(y, 0, 'e', 5));
}

// Method for starting the simulation
void MainWindow::startSimulation(){
    integrateOrbitSim.orbitSim.angle = integrateOrbitSim.orbitSim.pi/2;
    integrateOrbitSim.orbitSim.orbitCounter = 0;
    integrateOrbitSim.orbitSim.posX = integrateOrbitSim.orbitSim.planetMoonDistance * cos(integrateOrbitSim.orbitSim.angle);
    integrateOrbitSim.orbitSim.posY = integrateOrbitSim.orbitSim.planetMoonDistance * sin(integrateOrbitSim.orbitSim.angle);

    startBtn->setEnabled(false);
    stopBtn->setEnabled(true);

    simTimeElapsed.restart();
    simTimer->start(timeInterval);
    stopwatchTimer->start(1);
}

// Method for stopping the simulation
void MainWindow::stopSimulation(){
    simTimer->stop();
    stopwatchTimer->stop();
    startBtn->setEnabled(true);
    stopBtn->setEnabled(false);
}

// Method for updating the planet selected
void MainWindow::planetSelected(const QString &planet){
    if(planet == "Planets"){
        qDebug() << "Please select a planet from the dropdown menu.";
        return;
    }

    // This links the backend with the UI, we pass the planet we selected to the setPlanetType() function
    std::string planetString = planet.toStdString();
    bool isUpdated = integrateOrbitSim.orbitSim.setPlanetType(planetString);
    if(isUpdated){
        qDebug() << "Backend updated planet:" << planet;
        double minMoonMass = integrateOrbitSim.orbitSim.planetMass * 0.001;
        double maxMoonMass = integrateOrbitSim.orbitSim.planetMass * 0.1;
        moonMassRangeLabel->setText(QString("Valid Moon Mass Range: %1 [kg] to %2 [kg]").arg(minMoonMass).arg(maxMoonMass));
    }
    else{
        qDebug() << "Backend update INVALID";
    }
}

