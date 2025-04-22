#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QColor>
#include <qtimer.h>
#include <cstdint>

#include "fluidBody.hpp"
#include "fluidWorld.hpp"
#include "fluidRenderer.hpp"


class fluidEngine : public QObject {
	Q_OBJECT

public:
    fluidEngine(fluidPhysicsWorld *world, fluidPhysicsRenderer *renderer);
	void start();
	void stop();
	void addBody(fluidBody *body, uint8_t color[3]);
	void update();

	fluidPhysicsWorld *world;
	fluidPhysicsRenderer *renderer;
	QTimer *timer;
};