#ifndef QTAPP_HPP
#define QTAPP_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>

// A simple QMainWindow for our Qt simulation GUI.
class QtApp : public QMainWindow {
    Q_OBJECT  // Enables signals and slots

public:
    explicit QtApp(QWidget *parent = nullptr);

private slots:
    // Slot called when the Start Simulation button is clicked.
    void runSim();

private:
    // Input fields for simulation parameters.
    QLineEdit *massEdit;
    QLineEdit *gravityEdit;
    QLineEdit *angleEdit;
    QLineEdit *lengthEdit;
    QLineEdit *frictionEdit;
    QLineEdit *extForceEdit;
    QLineEdit *shapeEdit;
    QLineEdit *materialEdit;

    // Text area to display simulation results.
    QTextEdit *outputView;

    // Button to start the simulation.
    QPushButton *startButton;
};

#endif // QTAPP_HPP
