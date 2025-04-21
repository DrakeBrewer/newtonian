#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsview.h>

#include "fluidShapes.hpp"

EllipseRender::EllipseRender(fluidEllipse *ellipse, QColor color, QGraphicsItem *parent) : QGraphicsEllipseItem(parent) {
	this->physEllipse = ellipse;
	this->color = color;

	this->setRect(0, 0, ellipse->radius*2, ellipse->radius*2);
    this->setPen(Qt::NoPen);
	this->setBrush(QBrush(color));

	this->updatePosition();
}

void EllipseRender::updatePosition() {
	this->setPos(
		this->physEllipse->position.x - this->physEllipse->radius,
		this->physEllipse->position.z - this->physEllipse->radius
	);
}

RectRender::RectRender(fluidRectangle *rect, QColor color, QGraphicsItem *parent) : QGraphicsRectItem(parent) {
	this->physRectangle = rect;
	this->color = color;

	this->setRect(0, 0, rect->width, rect->height);
    this->setPen(Qt::NoPen);
	this->setBrush(QBrush(color));

	this->updatePosition();
}

void RectRender::updatePosition() {
	this->setPos(
		this->physRectangle->position.x,
		this->physRectangle->position.z
	);
}