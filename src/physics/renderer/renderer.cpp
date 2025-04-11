#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QColor>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QtWidgets/qgraphicsview.h>
#include <qtimer.h>

#include "renderer.hpp"
#include "shapes.hpp"
#include "rigidBody.hpp"
#include "vector3d.hpp"
#include "physicsView.hpp"

PhysicsRenderer::PhysicsRenderer(PhysicsWorld *world, QGraphicsScene *scene, QObject *parent) :
	QObject(parent), world(world), scene(scene) {
	this->bgColor = Qt::white;

	this->view = new PhysicsView(scene);
	view->setRenderHint(QPainter::Antialiasing);
	view->setBackgroundBrush(this->bgColor);
	view->setMinimumSize(800, 600);
	// view->setDragMode(QGraphicsView::ScrollHandDrag);

	// Qt has the pos Y direction as downward for some reason
	//  so we need to flip it.
	view->scale(1, -1);

	this->scene->setSceneRect(-300, -200, 1000, 1000);
}


PhysicsRenderer::~PhysicsRenderer() {
	for (auto& pair : bodyToRender) {
		this->scene->removeItem(pair.second);
		delete pair.second;
	}

	bodyToRender.clear();
}

void PhysicsRenderer::drawGrid() {
	// TODO: Implement
}

void PhysicsRenderer::addBody(RigidBody *body, QColor color) {
	QGraphicsItem *item = attachRenderItem(body, color);

	if (item != nullptr) {
		this->scene->addItem(item);
		bodyToRender[body] = item;
	}
}

void PhysicsRenderer::removeBody(RigidBody *body) {
	auto item = bodyToRender.find(body);
	if (item != bodyToRender.end()) {
		this->scene->removeItem(item->second);
		delete item->second;
		bodyToRender.erase(item);
	}
}

void PhysicsRenderer::start() {
	this->timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &PhysicsRenderer::updateRender);
	this->timer->start(16);
}

void PhysicsRenderer::stop() {
	if (timer) {
		timer->stop();
		disconnect(this->timer, &QTimer::timeout, this, &PhysicsRenderer::updateRender);
		delete this->timer;
		timer = nullptr;
	}
}

// TODO:
// Find alternative to dynamic casting?
void PhysicsRenderer::updateRender() {
	this->world->tick(0.016);
	for (auto& pair : this->bodyToRender) {
		RigidBody *body = pair.first;
		QGraphicsItem *item = pair.second;

		EllipseRender *e = dynamic_cast<EllipseRender*>(item);
		if (e) {
			e->updatePosition();
			continue;
		}

		RectRender *r = dynamic_cast<RectRender*>(item);
		if (r) {
			r->updatePosition();
			continue;
		}

		item->setPos(body->position.x, body->position.z);
	}

	this->scene->update();
}


// TODO:
// Find alternative to dynamic casting?
QGraphicsItem *attachRenderItem(RigidBody *body, QColor color) {
	QGraphicsItem *gItem = nullptr;

	Ellipse *e = dynamic_cast<Ellipse*>(body);
	if (e) {
		EllipseRender *er = new EllipseRender(e, color, nullptr);
		gItem = er;
	}

	Rectangle *r = dynamic_cast<Rectangle*>(body);
	if (r) {
		RectRender *rr = new RectRender(r, color, nullptr);
		gItem = rr;
	}

	return gItem;
}

