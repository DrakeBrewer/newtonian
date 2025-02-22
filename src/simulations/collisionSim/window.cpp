#include <QMenuBar>

#include "window.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	// this->physicsView = new GlView;

	// setCentralView(this->physicsView);

	QMenuBar *menuBar = new QMenuBar(nullptr);
}

MainWindow::~MainWindow() {
}
