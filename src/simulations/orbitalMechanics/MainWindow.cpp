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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Orbital Mechanics Simulator");
    resize(1000,800);

    // Central widget, vertical and horizontal layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Planet Selection Dropdown
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

    // Setting the Moon Mass

    // Moon Mass Label
    QLabel *moonMassLabel = new QLabel("Set Moon Mass [kg]", centralWidget);
    moonMassLabel->setStyleSheet("font-size: 16pt; font-weight: bold;");
    mainLayout->addWidget(moonMassLabel);

    // Show the valid moon mass range
    moonMassRangeLabel = new QLabel(centralWidget);
    moonMassRangeLabel->setStyleSheet("font-size: 12pt;");
    double minMoonMass = integrateOrbitSim.orbitSim.planetMass * 0.001;
    double maxMoonMass = integrateOrbitSim.orbitSim.planetMass * 0.1;
    moonMassRangeLabel->setText(QString("Valid Moon Mass Range: %1 [kg] to %2 [kg]").arg(minMoonMass).arg(maxMoonMass));
    mainLayout->addWidget(moonMassRangeLabel, 0, Qt::AlignLeft);

    mainLayout->addStretch();
}

MainWindow::~MainWindow(){

}

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

