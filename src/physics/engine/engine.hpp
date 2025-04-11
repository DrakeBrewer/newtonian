#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QColor>
#include <qtimer.h>
#include <cstdint>

#include "rigidBody.hpp"
#include "world.hpp"
#include "renderer.hpp"


class Engine : public QObject {
	Q_OBJECT

public:
	Engine(PhysicsWorld *world, PhysicsRenderer *renderer);
	void start();
	void stop();
	void addBody(RigidBody *body, uint8_t color[3]);
	void update();

	PhysicsWorld *world;
	PhysicsRenderer *renderer;
	QTimer *timer;
};
