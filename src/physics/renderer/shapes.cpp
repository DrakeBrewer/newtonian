#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsview.h>

#include "shapes.hpp"


LightRender::LightRender(LightBody *light, QColor color, QGraphicsItem *parent) : 
	QGraphicsItem(parent),
	light(light),
	color(color),
	radius(2.0f),
	pen(color), 
	brush(color)
{}


QRectF LightRender::boundingRect() const {
	float d = radius + 1.0f;
	return QRectF(-d, -d, 2*d, 2*d);
}

void LightRender::paint(QPainter *p, const QStyleOptionGraphicsItem*, QWidget*){
	p->setPen(Qt::NoPen);
	p->setBrush(brush);
	p->drawEllipse(-radius, -radius, 2*radius, 2*radius);
	// trailing rect
	p->setPen(pen);
	QPointF tip(light->direction.x *-10.0f, light->direction.z * -10.0f);
	p->drawLine(QPointF(0,0), tip);
}

void LightRender::updatePosition() {
	setPos(light->position.x, light->position.z);
	update();
}

EllipseRender::EllipseRender(Ellipse *ellipse, QColor color, QGraphicsItem *parent) : QGraphicsEllipseItem(parent) {
	this->physEllipse = ellipse;
	this->color = color;

	this->setRect(0, 0, ellipse->radius*2, ellipse->radius*2);
	this->setBrush(QBrush(color));
	this->setPen(Qt::NoPen);

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
	this->setPen(Qt::NoPen);

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
	this->setPen(Qt::NoPen);

	this->updatePosition();
}

void TriangleRender::updatePosition() {
	this->setPos(
		this->physTriangle->position.x - int(this->physTriangle->width / 2),
		this->physTriangle->position.z - int(this->physTriangle->height / 2)
	);
}
