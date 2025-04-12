#include "QtApp.hpp"
#include <QVBoxLayout>
#include <QMessageBox>
#include <sstream>
#include "planeInteractionMech.hpp"  // For simulation calculations

QtApp::QtApp(QWidget *parent)
    : QMainWindow(parent)
{
    // Create a central widget and a vertical layout.
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create input fields with default values.
    massEdit = new QLineEdit("10.0", this);
    gravityEdit = new QLineEdit("9.81", this);
    angleEdit = new QLineEdit("30.0", this);
    lengthEdit = new QLineEdit("5.0", this);
    frictionEdit = new QLineEdit("0.1", this);
    extForceEdit = new QLineEdit("0.0", this);
    shapeEdit = new QLineEdit("Cube", this);
    materialEdit = new QLineEdit("Steel", this);

    // Add input fields to the layout.
    layout->addWidget(massEdit);
    layout->addWidget(gravityEdit);
    layout->addWidget(angleEdit);
    layout->addWidget(lengthEdit);
    layout->addWidget(frictionEdit);
    layout->addWidget(extForceEdit);
    layout->addWidget(shapeEdit);
    layout->addWidget(materialEdit);

    // Create a button to start the simulation.
    startButton = new QPushButton("Start Simulation", this);
    layout->addWidget(startButton);

    // Create an output text area.
    outputView = new QTextEdit(this);
    outputView->setReadOnly(true);
    outputView->setPlaceholderText("Simulation results will appear here...");
    layout->addWidget(outputView);

    setCentralWidget(centralWidget);
    setWindowTitle("Simple Qt Simulation");

    // Connect the Start Simulation button to its slot.
    connect(startButton, &QPushButton::clicked, this, &QtApp::runSim);
}

void QtApp::runSim() {
    bool ok;
    double mass = massEdit->text().toDouble(&ok);      if (!ok) mass = 10.0;
    double gravity = gravityEdit->text().toDouble(&ok);  if (!ok) gravity = 9.81;
    double angle = angleEdit->text().toDouble(&ok);      if (!ok) angle = 30.0;
    double length = lengthEdit->text().toDouble(&ok);    if (!ok) length = 5.0;
    double friction = frictionEdit->text().toDouble(&ok);  if (!ok) friction = 0.1;
    double extForce = extForceEdit->text().toDouble(&ok);  if (!ok) extForce = 0.0;
    std::string shape = shapeEdit->text().toStdString();
    std::string material = materialEdit->text().toStdString();

    // Create a simulation object.
    InclinedPlaneMechanics sim(mass, gravity, angle, length, friction, extForce, shape, material);
    double netForce = sim.calculateNetForce();
    double acceleration = sim.calculateAcceleration();

    // Build simulation result text.
    std::ostringstream oss;
    oss << "Net Force: " << netForce << " N\n"
        << "Acceleration: " << acceleration << " m/s^2\n"
        << (sim.willSlide() ? "The object will slide." : "The object will not slide.");
    outputView->setPlainText(QString::fromStdString(oss.str()));
}
