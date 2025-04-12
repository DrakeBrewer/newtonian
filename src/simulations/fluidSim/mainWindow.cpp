#include "mainWindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

    // Title and initial window size
    setWindowTitle("Fluid Simulation");
    resize(1000,1000);

    // Change the background color to green
    QPalette pal = palette();
    pal.setColor(QPalette::Window,Qt::green);
    setAutoFillBackground(true);
    setPalette(pal);

    // Initialize buttons
    //startButton = new QPushButton("Start",this);//'This' makes the button a child of the window
    //startButton -> move(350,300);
    
    //Connect the startButton 'Clicked' signal to trigger the the runSim slot in the app
    //connect(startButton, &QPushButton::clicked, this, &QtApp::startApp);
    
    quitButton = new QPushButton("Quit",this);
    quitButton -> move(800,900);
    
    //Connect the quitButton signal to trigger application exit
    connect(quitButton, &QPushButton::clicked,this,&QApplication::quit);
}

// Need: to get my sim to work with Qt

//void QtApp::startApp(){
//
//    configWindow = new simConfigWindow(this);
//    configWindow -> show();
//}


