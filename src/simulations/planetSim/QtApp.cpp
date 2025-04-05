#include "QtApp.hpp"
#include "planets.hpp"


QtApp::QtApp(QWidget *parent) : QMainWindow(parent){

    //Title and initial size
    setWindowTitle("PlanetSim");
    resize(1000,1000);

    //Change the background color
    QPalette pal = palette();
    pal.setColor(QPalette::Window,Qt::blue);
    setAutoFillBackground(true);
    setPalette(pal);

    //Initialize buttons
    startButton = new QPushButton("Start",this);//'This' makes the button a child of the window
    //startButton -> move(350,300);
    
    //Connect the startButton 'Clicked' signal to trigger the the runSim slot in the app
    connect(startButton, &QPushButton::clicked, this, &QtApp::startApp);
    
    quitButton = new QPushButton("Quit",this);
    //quitButton -> move(350,500);
    
    //Connect the quitButton signal to trigger application exit
    connect(quitButton, &QPushButton::clicked,this,&QApplication::quit);

    QVBoxLayout *vLayout = new QVBoxLayout();

    vLayout -> addStretch();

    QHBoxLayout *startLayout = new QHBoxLayout();
    startLayout -> addStretch();
    startLayout -> addWidget(startButton);
    startLayout-> addStretch();

    vLayout -> addLayout(startLayout);

    vLayout -> addSpacing(30);

    QHBoxLayout *quitLayout = new QHBoxLayout();
    quitLayout -> addStretch();
    quitLayout -> addWidget(quitButton);
    quitLayout -> addStretch();

    vLayout -> addLayout(quitLayout);

    vLayout -> addStretch();

    QWidget *centralWidget = new QWidget(this);
    centralWidget -> setLayout(vLayout);
    setCentralWidget(centralWidget);



}

void QtApp::startApp(){

    configWindow = new simConfigWindow(this);
    configWindow -> show();
}



