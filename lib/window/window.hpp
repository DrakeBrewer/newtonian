#pragma once

#include <QMainWindow>
#include <QtWidgets/qwidget.h>

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
};

// TODO: Turn sidebar into a class
// class Sidebar : public QWidget {
// 	Q_OBJECT
// public:
// 	Sidebar(QWidget *parent = nullptr);
// };
