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

	// posistion point is the middle of the rect
	this->setRect(-rect->width/2, -rect->height/2, rect->width, rect->height);
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

TriangleRender::TriangleRender(fluidTriangle *triangle, QColor color, QGraphicsItem *parent) : QGraphicsPolygonItem(parent) {
	this->physTriangle = triangle;
	this->color = color;

	QPolygonF polygon;
	if(this->physTriangle->direction == 1){
		polygon << QPointF(-triangle->width/2, -triangle->height/2);
		polygon << QPointF(triangle->width/2, -triangle->height/2);
		polygon << QPointF(0, triangle->height/2);
	}
	else{
		polygon << QPointF(0, -triangle->height/2);
		polygon << QPointF(-triangle->width/2, triangle->height/2);
		polygon << QPointF(triangle->width/2, triangle->height/2);
	}

	this->setPolygon(polygon);
	this->setPen(Qt::NoPen);
	this->setBrush(QBrush(color));

	this->updatePosition();
}

void TriangleRender::updatePosition() {
	this->setPos(
		this->physTriangle->position.x - int(this->physTriangle->width / 2),
		this->physTriangle->position.z - int(this->physTriangle->height / 2)
	);
}

//  -----------Liquid------------

//  Just like the RectRender but used just for Liquids
LiquidRender::LiquidRender(fluidLiquid *liquid, QColor color, QGraphicsItem *parent) : QGraphicsRectItem(parent) {
	this->physLiquid = liquid;
	this->color = color;
	
	this->setRect(0, 0, liquid->width, liquid->height);
    this->setPen(Qt::NoPen);
	this->setBrush(QBrush(color));

	this->updatePosition();
}

void LiquidRender::updatePosition() {
	this->setPos(
		this->physLiquid->position.x,
		this->physLiquid->position.z
	);
}