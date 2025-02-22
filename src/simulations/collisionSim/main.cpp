#include <iostream>
#include <QWidget>
#include <QApplication>

#include "window.hpp"

int main(int argc, char **argv) {
	std::cout << "Hello World!" << std::endl;
	QApplication app(argc, argv);

	MainWindow mw;
	mw.show();

	return app.exec();
}
