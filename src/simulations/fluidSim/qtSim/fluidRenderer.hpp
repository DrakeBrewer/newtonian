#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QColor>

#include <cstdint>
#include <unordered_map>

#include "vector3d.hpp"
#include "fluidBody.hpp"
#include "fluidWorld.hpp"
#include "fluidShapes.hpp"


#include "fluidPhysicsView.hpp"

class fluidPhysicsRenderer : public QObject {
	Q_OBJECT

public:
    fluidPhysicsRenderer(fluidPhysicsWorld *world, QGraphicsScene *scene, QObject *parent = nullptr);
	~fluidPhysicsRenderer();

	void addBody(fluidBody *body, uint8_t color[3]);
	void removeBody(fluidBody *body);

	void updateRender();

	fluidPhysicsWorld *world;
	QGraphicsScene *scene;
	QGraphicsView *view;
	QTimer *timer;

	QColor bgColor;

	Vector3d cameraPosition;
	Vector3d cameraTarget;

	std::unordered_map<fluidBody*, QGraphicsItem*> bodyToRender;
};


QGraphicsItem *attachRenderItem(fluidBody *body, QColor color);