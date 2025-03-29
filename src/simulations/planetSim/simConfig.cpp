#include "simConfig.hpp"



simConfigWindow::simConfigWindow(QWidget *parent) : QWidget(parent){

    setWindowTitle("Configure Simulation");
    resize(1000,1000);

    QPalette pal = palette();
    pal.setColor(QPalette::Window,Qt::blue);
    setAutoFillBackground(true);
    setPalette(pal);

    startButton = new QPushButton("Start",this);
    startButton -> move(350,100);

    connect(startButton, &QPushButton::clicked, this, &simConfigWindow::startSim);

    quitButton = new QPushButton("Quit",this);
    quitButton -> move(350,150);

    connect(quitButton,&QPushButton::clicked,this, &QApplication::quit);


    selectPlanetLabel = new QLabel("Select Planet",this);
    selectPlanetLabel -> move(350,200);

    earthRadio = new QRadioButton("Earth", this);
    earthRadio -> move(50,250);

    moonRadio = new QRadioButton("Moon", this);
    moonRadio -> move(125,250);

    mercuryRadio = new QRadioButton("Mercury", this);
    mercuryRadio -> move(200,250);

    venusRadio = new QRadioButton("Venus", this);
    venusRadio -> move(275,250);

    marsRadio = new QRadioButton("Mars", this);
    marsRadio -> move(350,250);

    jupiterRadio = new QRadioButton("Jupiter", this);
    jupiterRadio -> move(425,250);

    saturnRadio = new QRadioButton("Saturn", this);
    saturnRadio -> move(500,250);

    uranusRadio = new QRadioButton("Uranus", this);
    uranusRadio -> move(575,250);

    neptuneRadio = new QRadioButton("Neptune", this);
    neptuneRadio -> move(650,250);

    objectInput = new QLineEdit(this);
    objectInput -> setPlaceholderText("Enter the object you wish to spawn");
    objectInput -> move(350,400 );

    massInput = new QLineEdit(this);
    massInput -> setPlaceholderText("Enter the object mass");
    massInput -> move(600, 500);

    initVInput = new QLineEdit(this);
    initVInput -> setPlaceholderText("Enter the objects initial velocity");
    initVInput -> move(600,550);

    xInput = new QLineEdit(this);
    xInput -> setPlaceholderText("Enter starting X value");
    xInput -> move(250, 500);

    yInput = new QLineEdit(this);
    yInput -> setPlaceholderText("Enter starting Y value");
    yInput -> move(250, 550);

    zInput = new QLineEdit(this);
    zInput -> setPlaceholderText("Enter Starting Z value");
    zInput -> move(250, 600);




}

void simConfigWindow::startSim(){
    planetSim();
}