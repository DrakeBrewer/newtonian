#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow {
	Q_OBJECT
// TODO: add privates for toolbars & stuff
// private:
	// GlView *physicsView;

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
};
