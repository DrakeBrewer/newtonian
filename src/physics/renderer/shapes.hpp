#include "rigidBody.hpp"
#include <QtGui/qcolor.h>
#include <QPainter>
#include <QtWidgets/qgraphicsitem.h>
#include <qpen.h>
#include "lightBody.hpp"

// circle + line showing photon and its direction
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class LightBody;

class LightRender: public QGraphicsItem {
public:
	LightRender(LightBody *light, QColor color, QGraphicsItem *parent=nullptr);

	QRectF boundingRect() const override;
	void paint(QPainter *p, const QStyleOptionGraphicsItem *opt, QWidget *widget) override;
	void updatePosition();

	LightBody *light;
	QColor color;
	float radius;
	QPen pen;
	QBrush brush;
};

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
	QGraphicsRectItem *debugRect;
};


class TriangleRender : public QGraphicsPolygonItem {
public:
	TriangleRender(Triangle *triangle, QColor color, QGraphicsItem *parent = nullptr);
	void updatePosition();

	Triangle *physTriangle;
	QColor color;
};
