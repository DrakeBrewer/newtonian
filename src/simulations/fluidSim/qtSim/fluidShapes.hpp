#pragma once

#include "fluidBody.hpp"
#include <QtGui/qcolor.h>
#include <QtWidgets/qgraphicsitem.h>

class EllipseRender : public QGraphicsEllipseItem {
public:
	EllipseRender(fluidEllipse *ellipse, QColor color, QGraphicsItem *parent = nullptr);
	void updatePosition();

	fluidEllipse *physEllipse;
	QColor color;
};

class RectRender : public QGraphicsRectItem {
public:
	RectRender(fluidRectangle *rect, QColor color, QGraphicsItem *parent = nullptr);
	void updatePosition();

	fluidRectangle *physRectangle;
	QColor color;
};

class LiquidRender : public QGraphicsRectItem {
	public:
	LiquidRender(fluidLiquid *liquid, QColor color, QGraphicsItem *parent = nullptr);
		void updatePosition();
	
		fluidLiquid *physLiquid;
		QColor color;
	};


class TriangleRender : public QGraphicsPolygonItem {
	public:
		TriangleRender(fluidTriangle *triangle, QColor color, QGraphicsItem *parent = nullptr);
		void updatePosition();
	
		fluidTriangle *physTriangle;
		QColor color;
	};
	