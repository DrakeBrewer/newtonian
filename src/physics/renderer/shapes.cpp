#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsview.h>

#include "shapes.hpp"

EllipseRender::EllipseRender(Ellipse *ellipse, QColor color, QGraphicsItem *parent) : QGraphicsEllipseItem(parent) {
	this->physEllipse = ellipse;
	this->color = color;

	int xPos = this->physEllipse->position.x - int(ellipse->radius);
	int yPos = this->physEllipse->position.z - int(ellipse->radius);

	this->setRect(xPos, yPos, ellipse->radius*2, ellipse->radius*2);
	this->setBrush(QBrush(color));
}

void EllipseRender::updatePosition() {
	this->setPos(
		this->physEllipse->position.x,
		this->physEllipse->position.z
	);
}

RectRender::RectRender(Rectangle *rect, QColor color, QGraphicsItem *parent) : QGraphicsRectItem(parent) {
	this->physRectangle = rect;
	this->color = color;

	int xPos = this->physRectangle->position.x - int(rect->width / 2);
	int yPos = this->physRectangle->position.z - int(rect->height / 2);

	this->setRect(xPos, yPos, rect->width, rect->height);
	this->setBrush(QBrush(color));
}

void RectRender::updatePosition() {
	this->setPos(
		this->physRectangle->position.x,
		this->physRectangle->position.z
	);
}
