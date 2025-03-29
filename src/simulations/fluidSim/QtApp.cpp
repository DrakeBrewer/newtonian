#include "QtApp.hpp"
#include <QDebug>
#include <QWidget>

QtApp::QtApp(QWidget *parent) : QMainWindow(parent){

    setWindowTitle("FluidSim");
    resize(750,750);

}


