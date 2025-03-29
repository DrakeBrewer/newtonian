#include "QtApp.hpp"
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

QtApp::QtApp(QWidget *parent)
    : QMainWindow(parent)
{
    // Create a central widget and set up a vertical layout.
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create the buttons.
    startButton = new QPushButton("Start Simulation", this);
    quitButton = new QPushButton("Quit", this);

    // Create an output text area.
    outputView = new QTextEdit(this);
    outputView->setReadOnly(true);
    outputView->setPlaceholderText("Simulation results will appear here...");

    // Add widgets to the layout.
    layout->addWidget(startButton);
    layout->addWidget(quitButton);
    layout->addWidget(outputView);

    // Set the central widget and the window title.
    setCentralWidget(centralWidget);
    setWindowTitle("Simple Qt Simulation");

    // Connect button clicks to their corresponding slots.
    connect(startButton, &QPushButton::clicked, this, &QtApp::runSim);
    connect(quitButton, &QPushButton::clicked, this, &QMainWindow::close);
}

void QtApp::runSim() {
    // When the simulation starts, show a message box and update the output text.
    QMessageBox::information(this, "Simulation", "Simulation would run here!");
    outputView->setPlainText("Simulation started...\nRunning simulation...\nSimulation complete!");
}
