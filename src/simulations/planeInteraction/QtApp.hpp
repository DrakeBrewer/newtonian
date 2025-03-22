#ifndef QTAPP_HPP
#define QTAPP_HPP

#include <QMainWindow>
#include <QPushButton>

// A simple QMainWindow for our Qt interface.
class QtApp : public QMainWindow {
    Q_OBJECT  // Required for signals and slots

public:
    // Constructor (with an optional parent widget)
    explicit QtApp(QWidget *parent = nullptr);

private slots:
    // Slot for handling the Start Simulation button click
    void runSim();

private:
    // Two basic buttons
    QPushButton *startButton;
    QPushButton *quitButton;
};

#endif // QTAPP_HPP
