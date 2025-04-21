#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsview.h>

#include "shapes.hpp"

EllipseRender::EllipseRender(Ellipse *ellipse, QColor color, QGraphicsItem *parent) : QGraphicsEllipseItem(parent) {
	this->physEllipse = ellipse;
	this->color = color;

	this->setRect(0, 0, ellipse->radius*2, ellipse->radius*2);
	this->setBrush(QBrush(color));

	this->updatePosition();
}

void EllipseRender::updatePosition() {
	this->setPos(
		this->physEllipse->position.x - this->physEllipse->radius,
		this->physEllipse->position.z - this->physEllipse->radius
	);
}

RectRender::RectRender(Rectangle *rect, QColor color, QGraphicsItem *parent) : QGraphicsRectItem(parent) {
	this->physRectangle = rect;
	this->color = color;

	this->setRect(0, 0, rect->width, rect->height);
	this->setBrush(QBrush(color));

	this->updatePosition();
}

void RectRender::updatePosition() {
	this->setPos(
		this->physRectangle->vertices[0].x,
		this->physRectangle->vertices[0].z
	);
}

TriangleRender::TriangleRender(Triangle *triangle, QColor color, QGraphicsItem *parent) : QGraphicsPolygonItem(parent) {
	this->physTriangle = triangle;
	this->color = color;

	QPolygonF polygon;
	polygon << QPointF(0, 0);
	polygon << QPointF(triangle->width, 0);
	polygon << QPointF(int(triangle->width / 2), triangle->height);

	this->setPolygon(polygon);
	this->setBrush(QBrush(color));

	this->updatePosition();
}

void TriangleRender::updatePosition() {
	this->setPos(
		this->physTriangle->position.x - int(this->physTriangle->width / 2),
		this->physTriangle->position.z - int(this->physTriangle->height / 2)
	);
}
