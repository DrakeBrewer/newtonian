#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QColor>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QtCore/qnamespace.h>
#include <QtWidgets/qgraphicsview.h>
#include <qtimer.h>

#include "fluidRenderer.hpp"
#include "fluidShapes.hpp"
#include "fluidBody.hpp"
#include "vector3d.hpp"
#include "fluidPhysicsView.hpp"

fluidPhysicsRenderer::fluidPhysicsRenderer(fluidPhysicsWorld *world, QGraphicsScene *scene, QObject *parent) :
	QObject(parent), world(world), scene(scene) {
	this->bgColor = Qt::white;

	this->view = new fluidPhysicsView(scene);
	view->setRenderHint(QPainter::Antialiasing);
	view->setBackgroundBrush(this->bgColor);
	view->setMinimumSize(800, 600);

	// Qt has the pos Y direction as downward for some reason
	//  so we need to flip it.
	view->scale(1, -1);

	this->scene->setSceneRect(-10, -1, 20, 20);
	//this->drawGrid();

	view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}


fluidPhysicsRenderer::~fluidPhysicsRenderer() {
	for (auto& pair : bodyToRender) {
		this->scene->removeItem(pair.second);
		delete pair.second;
	}

	bodyToRender.clear();
}


void fluidPhysicsRenderer::addBody(fluidBody *body, uint8_t color[3]) {
	QColor c = QColor(color[0], color[1], color[2]);
	QGraphicsItem *item = attachRenderItem(body, c);

	if (item != nullptr) {
		this->scene->addItem(item);
		bodyToRender[body] = item;
	}
}

void fluidPhysicsRenderer::removeBody(fluidBody *body) {
	auto item = bodyToRender.find(body);
	if (item != bodyToRender.end()) {
		this->scene->removeItem(item->second);
		delete item->second;
		bodyToRender.erase(item);
	}
}


void fluidPhysicsRenderer::updateRender() {
	// this->world->tick(0.016);
	for (auto& pair : this->bodyToRender) {
		fluidBody *body = pair.first;
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


QGraphicsItem *attachRenderItem(fluidBody *body, QColor color) {
	QGraphicsItem *gItem = nullptr;

	fluidEllipse *e = dynamic_cast<fluidEllipse*>(body);
	if (e) {
		EllipseRender *er = new EllipseRender(e, color, nullptr);
		gItem = er;
	}

	fluidRectangle *r = dynamic_cast<fluidRectangle*>(body);
	if (r) {
		RectRender *rr = new RectRender(r, color, nullptr);
		gItem = rr;
	}

	return gItem;
}