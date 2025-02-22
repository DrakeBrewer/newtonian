#include <QMenuBar>
#include <QtWidgets/QtWidgets>
#include <QtWidgets/qtoolbar.h>
#include <QtWidgets/qwidget.h>

#include "window.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	QWidget *mainWidget = new QWidget(this);
	setCentralWidget(mainWidget);

	QHBoxLayout *layout = new QHBoxLayout(mainWidget);
	mainWidget->setLayout(layout);

	QWidget *sidebar = new QWidget(parent);
	sidebar->setFixedWidth(200);
	sidebar->setStyleSheet("background: #737373;");
	sidebar->setStyleSheet("border-left: 2px solid #3e3e3e;");

	// TODO: this should be the physics view, rendered with opengl
	QWidget *mainContent = new QWidget(mainWidget);
	mainContent->setStyleSheet("background: #5feaff;");

	layout->addWidget(mainContent);
	layout->addWidget(sidebar);

	layout->setStretchFactor(mainContent, 1);
	layout->setStretchFactor(sidebar, 0);
	layout->setContentsMargins(0, 0, 0, 0);

	setWindowTitle("BLAM!");
	setMouseTracking(true);
	
}


MainWindow::~MainWindow() {
}
