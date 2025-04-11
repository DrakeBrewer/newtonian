#include <QApplication>
#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsscene.h>
#include <QtWidgets/qgraphicsview.h>

#include "renderer.hpp"
#include "rigidBody.hpp"
#include "shapes.hpp"
#include "vector3d.hpp"
#include "world.hpp"

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	QGraphicsScene *scene = new QGraphicsScene();

	Rectangle *rect = new Rectangle(100, 155, Vector3d(), 100);
	Ellipse *ellipse = new Ellipse(20, Vector3d(-50, -50, -50), 5);

	PhysicsWorld *world = new PhysicsWorld(9.81);
	world->addBody(rect);
	world->addBody(ellipse);

	PhysicsRenderer *renderer = new PhysicsRenderer(world, scene, nullptr);
	renderer->addBody(rect, QColor(100, 220, 50));
	renderer->addBody(ellipse, QColor(255, 0, 0));

	renderer->view->show();
	renderer->start();

	return app.exec();
}
