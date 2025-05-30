#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QColor>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QtCore/qnamespace.h>
#include <QtWidgets/qgraphicsview.h>
#include <qtimer.h>

#include "renderer.hpp"
#include "shapes.hpp"
#include "rigidBody.hpp"
#include "vector3d.hpp"
#include "physicsView.hpp"
#include "lightBody.hpp"

PhysicsRenderer::PhysicsRenderer(PhysicsWorld *world, QGraphicsScene *scene, QObject *parent) :
	QObject(parent), world(world), scene(scene) {
	this->bgColor = Qt::white;

	this->view = new PhysicsView(scene);
	view->setRenderHint(QPainter::Antialiasing);
	view->setBackgroundBrush(this->bgColor);
	view->setMinimumSize(600, 600);

	// Qt has the pos Y direction as downward for some reason
	//  so we need to flip it.
	view->scale(1, -1);

	this->scene->setSceneRect(-150, -150, 300, 300);
	//this->drawGrid();

	view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
	view->centerOn(0,0);
}

PhysicsRenderer::~PhysicsRenderer() {
	for (auto& pair : bodyToRender) {
		this->scene->removeItem(pair.second);
		delete pair.second;
	}

	bodyToRender.clear();
}

void PhysicsRenderer::drawGrid() {
	int space = 50;
	QGraphicsLineItem *xAxis = scene->addLine(-5000, 0, 5000, 0, QPen(Qt::black, 2));
	QGraphicsLineItem *yAxis = scene->addLine(0, -5000, 0, 5000, QPen(Qt::black, 2));

	for (int i = 0; i < 100; i++) {
		QGraphicsLineItem *xAxis = scene->addLine(-5000, space*i, 5000, space*i, QPen(Qt::gray, 1));
		QGraphicsLineItem *yAxis = scene->addLine(space*i, -5000, space*i, 5000, QPen(Qt::gray, 1));
	}

	for (int i = 0; i > -100; i--) {
		QGraphicsLineItem *xAxis = scene->addLine(-5000, space*i, 5000, space*i, QPen(Qt::gray, 1));
		QGraphicsLineItem *yAxis = scene->addLine(space*i, -5000, space*i, 5000, QPen(Qt::gray, 1));
	}
}

void PhysicsRenderer::addBody(RigidBody *body, uint8_t color[3]) {
	QColor c = QColor(color[0], color[1], color[2]);
	QGraphicsItem *item = attachRenderItem(body, c);

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

// TODO:
// Find alternative to dynamic casting?
void PhysicsRenderer::updateRender() {
	// this->world->tick(0.016);
	for (auto& pair : this->bodyToRender) {
		RigidBody *body = pair.first;
		QGraphicsItem *item = pair.second;

		LightRender *rayRender = dynamic_cast<LightRender*>(item);
		if(rayRender) {
			rayRender->updatePosition();
			continue;
		}

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

		TriangleRender *t = dynamic_cast<TriangleRender*>(item);
		if (t) {
			t->updatePosition();
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

	LightBody *ray = dynamic_cast<LightBody*>(body);
	if(ray) {
		LightRender *rayRender = new LightRender(ray, color, nullptr);
		gItem = rayRender;
	}

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

	Triangle *t = dynamic_cast<Triangle*>(body);
	if (t) {
		TriangleRender *tr = new TriangleRender(t, color, nullptr);
		gItem = tr;
	}

	return gItem;
}

