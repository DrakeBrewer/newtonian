#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QColor>

#include <unordered_map>

#include "vector3d.hpp"
#include "world.hpp"
#include "rigidBody.hpp"

class PhysicsRenderer : public QObject {
	Q_OBJECT

private:
	void drawGrid();
public:
	PhysicsRenderer(PhysicsWorld *world, QGraphicsScene *scene, QObject *parent = nullptr);
	~PhysicsRenderer();


	void addBody(RigidBody *body, QColor color);
	void removeBody(RigidBody *body);

	void start();
	void stop();

	void updateRender();

	PhysicsWorld *world;
	QGraphicsScene *scene;
	QGraphicsView *view;
	QTimer *timer;

	QColor bgColor;

	Vector3d cameraPosition;
	Vector3d cameraTarget;

	std::unordered_map<RigidBody*, QGraphicsItem*> bodyToRender;
};


QGraphicsItem *attachRenderItem(RigidBody *body, QColor color);
