#pragma once

#include <QGraphicsView>
#include <QWheelEvent>

class fluidPhysicsView : public QGraphicsView {
public:
    fluidPhysicsView(QGraphicsScene *scene = nullptr, QWidget *parent = nullptr) : QGraphicsView(scene, parent) {};
protected:
	void wheelEvent(QWheelEvent *e);
};