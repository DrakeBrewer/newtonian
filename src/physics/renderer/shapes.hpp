#include "rigidBody.hpp"
#include <QtGui/qcolor.h>
#include <QtWidgets/qgraphicsitem.h>

class SphereRender: public QGraphicsEllipseItem {
public:
	SphereRender(Sphere *sphere, QGraphicsItem *parent = nullptr);
	void updatePosition();

	Sphere *physicalSphere;
	QColor color;
};

class CuboidRender : public QGraphicsPolygonItem {
public:
	CuboidRender(Cuboid *cuboid, QGraphicsItem *parent = nullptr);
	void updatePosition();

	Cuboid *physicalCuboid;
	QColor color;
};

class EllipseRender : public QGraphicsEllipseItem {
public:
	EllipseRender(Ellipse *ellipse, QColor color, QGraphicsItem *parent = nullptr);
	void updatePosition();

	Ellipse *physEllipse;
	QColor color;
};

class RectRender : public QGraphicsRectItem {
public:
	RectRender(Rectangle *rect, QColor color, QGraphicsItem *parent = nullptr);
	void updatePosition();

	Rectangle *physRectangle;
	QColor color;
};


class TriangleRender : public QGraphicsPolygonItem {
public:
	TriangleRender(Triangle *triangle, QColor color, QGraphicsItem *parent = nullptr);
	void updatePosition();

	Triangle *physTriangle;
	QColor color;
};
