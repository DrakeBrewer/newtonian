#include <iostream>
#include <QWidget>
#include <QApplication>

#include "window.hpp"

int main(int argc, char **argv) {
	std::cout << "Hello World!" << std::endl;
	QApplication app(argc, argv);

	// TODO: Render a window
	// QWidget window;

	MainWindow mw;
	mw.show();

	// window.resize(500, 500);
	// window.show();
	// window.setWindowTitle(QApplication::translate("test", "my-test"));
	return app.exec();
}
