#include <qtimer.h>

#include "fluidEngine.hpp"
#include "fluidRenderer.hpp"
#include "fluidBody.hpp"

fluidEngine::fluidEngine(fluidPhysicsWorld *world, fluidPhysicsRenderer *renderer) {
	this->world = world;
	this->renderer = renderer;
}

void fluidEngine::start() {
	this->timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &fluidEngine::update);
	this->timer->start(25);
	this->renderer->view->show();
}

void fluidEngine::stop() {
	if (timer) {
		timer->stop();
		disconnect(this->timer, &QTimer::timeout, this, &fluidEngine::update);
		delete this->timer;
		timer = nullptr;
	}
}

void fluidEngine::addBody(fluidBody *body, uint8_t color[3]) {
	this->world->addBody(body, color);
	this->renderer->addBody(body, color);
}

void fluidEngine::update() {
	this->world->tick(0.005);
	this->renderer->updateRender();
}