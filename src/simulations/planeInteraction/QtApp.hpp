#ifndef QTAPP_HPP
#define QTAPP_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

// A simple QMainWindow for our simulation GUI.
class QtApp : public QMainWindow {
    Q_OBJECT  // Required for signals and slots

public:
    // Constructor, with optional parent.
    explicit QtApp(QWidget *parent = nullptr);

private slots:
    // Slot that handles the simulation when the button is clicked.
    void runSim();

private:
    // Buttons for starting simulation and quitting.
    QPushButton *startButton;
    QPushButton *quitButton;
    // Text area to display simulation results.
    QTextEdit *outputView;
};

#endif // QTAPP_HPP
