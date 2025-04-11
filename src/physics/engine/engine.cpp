#include <cstdint>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QColor>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QtCore/qnamespace.h>
#include <QtWidgets/qgraphicsview.h>
#include <qtimer.h>

#include "engine.hpp"
#include "renderer.hpp"
#include "rigidBody.hpp"

Engine::Engine(PhysicsWorld *world, PhysicsRenderer *renderer) {
	this->world = world;
	this->renderer = renderer;
}

void Engine::start() {
	this->timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &Engine::update);
	this->timer->start(16);
	this->renderer->view->show();
}

void Engine::stop() {
	if (timer) {
		timer->stop();
		disconnect(this->timer, &QTimer::timeout, this, &Engine::update);
		delete this->timer;
		timer = nullptr;
	}
}

void Engine::addBody(RigidBody *body, uint8_t color[3]) {
	this->world->addBody(body, color);
	this->renderer->addBody(body, color);
}

void Engine::update() {
	this->world->tick(0.016);
	this->renderer->updateRender();
}
