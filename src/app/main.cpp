#include <QApplication>

#include "window/window.hpp"

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	MainWindow mw;
	mw.show();

	return app.exec();
}
