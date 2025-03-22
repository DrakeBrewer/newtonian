#include "QtApp.hpp"
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

QtApp::QtApp(QWidget *parent)
    : QMainWindow(parent)
{
    // Create a central widget and a vertical layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create the buttons
    startButton = new QPushButton("Start Simulation", this);
    quitButton  = new QPushButton("Quit", this);

    // Add buttons to the layout
    layout->addWidget(startButton);
    layout->addWidget(quitButton);

    // Set the central widget and window title
    setCentralWidget(centralWidget);
    setWindowTitle("Simple Qt Simulation");

    // Connect the button clicks to their respective slots
    connect(startButton, &QPushButton::clicked, this, &QtApp::runSim);
    connect(quitButton, &QPushButton::clicked, this, &QMainWindow::close);
}

void QtApp::runSim() {
    // For now, just show a message box when the simulation is started
    QMessageBox::information(this, "Simulation", "Simulation would run here!");
}
