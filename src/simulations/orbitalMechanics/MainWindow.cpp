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

    // Moon Mass Input Field
    QVBoxLayout *moonMassInputLayout = new QVBoxLayout();
    QLineEdit *moonMassInput = new QLineEdit(centralWidget);
    moonMassInput->setPlaceholderText("Enter in Scientific Notation then press ENTER...");
    moonMassInput->setStyleSheet("font-size: 12pt;");
    moonMassInput->setFixedWidth(330);
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
        double minMoonMass = integrateOrbitSim.getMinMoonMass();
        double maxMoonMass = integrateOrbitSim.getMaxMoonMass();
        moonMassRangeLabel->setText(QString("Valid Moon Mass Range: %1 [kg] to %2 [kg]").arg(minMoonMass).arg(maxMoonMass));
    });
    mainLayout->addSpacing(21);

    // Update Moon Velocity ------------------------------------------------------------------
    QLabel *updateVelocityLabel = new QLabel("Update Moon Velocity [m/s]", centralWidget);
    updateVelocityLabel->setStyleSheet("font-size: 16pt; font-weight: bold;");
    mainLayout->addWidget(updateVelocityLabel);
    mainLayout->addSpacing(21);


    // Update Planet Mass --------------------------------------------------------------------
    QLabel *updatePlanetMassLabel = new QLabel("Update Planet Mass [kg]", centralWidget);
    updatePlanetMassLabel->setStyleSheet("font-size: 16pt; font-weight: bold;");
    mainLayout->addWidget(updatePlanetMassLabel);
    mainLayout->addSpacing(21);


    // Update Planet to Moon Distance --------------------------------------------------------
    QLabel *updateDistanceLabel = new QLabel("Update Planet to Moon Distance [m]", centralWidget);
    updateDistanceLabel->setStyleSheet("font-size: 16pt; font-weight: bold;");
    mainLayout->addWidget(updateDistanceLabel);



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

