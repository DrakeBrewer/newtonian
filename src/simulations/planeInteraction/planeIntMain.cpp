#include <iostream>
#include "planeInteractionSim.hpp"
#include <limits>
#include <cstring>
#include <QApplication>
#include "QtApp.hpp"

int main(int argc, char* argv[]) {
    // If "console" is passed as an argument, run in console mode.
    if (argc > 1 && std::strcmp(argv[1], "console") == 0) {
        std::cout << "Welcome to the Inclined Plane Simulation (Console Mode)!" << std::endl;
        char choice = 'y';
        while (choice == 'y' || choice == 'Y') {
            // Run a single simulation iteration.
            runPlaneSimulation();
            std::cout << "\nWould you like to run another simulation? (y/n): ";
            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
        }
        std::cout << "Thank you for using the Inclined Plane Simulation. Goodbye!" << std::endl;
        return 0;
    } else {
        // Otherwise, launch the Qt GUI.
        QApplication app(argc, argv);
        QtApp window;
        window.show();
        return app.exec();
    }
}
