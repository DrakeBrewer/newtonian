#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPalette>

#include "mainWindow.hpp"



int main(int argc, char *argv[]){
    
    QApplication app(argc, argv); // Initalize the QT event loop
    
    MainWindow mainWindow; // Create an instance of the mainwindow
    mainWindow.show();     // Display the window

    return app.exec(); // Start the app
};