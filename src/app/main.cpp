#include <QApplication>
#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsscene.h>
#include <QtWidgets/qgraphicsview.h>
#include <sys/types.h>

#include "renderer.hpp"
#include "rigidBody.hpp"
#include "shapes.hpp"
#include "vector3d.hpp"
#include "world.hpp"
#include "engine.hpp"


int main(int argc, char **argv) {
	QApplication app(argc, argv);

	QGraphicsScene *scene = new QGraphicsScene();

	Rectangle *rect = new Rectangle(1000, 200, Vector3d(0, 0, 0), 100, true);
	Triangle *rect1 = new Triangle(50, 50, Vector3d(-500, 0, 250), 5, false);
	// Ellipse *ellipse = new Ellipse(50, Vector3d(1000, 0, -950), 5, false);
	int i = 1000;
	// ellipse->velocity = Vector3d(-i, 0, i);
	// Ellipse *ellipse1 = new Ellipse(100, Vector3d(0, 0, 0), 5, true);
	// Triangle *triangle = new Triangle(50, 50, Vector3d(0, 0, 200), 100, false);
	// triangle->velocity = Vector3d(0, 0, 900);

	PhysicsWorld *world = new PhysicsWorld(9.81f);
	PhysicsRenderer *renderer = new PhysicsRenderer(world, scene, nullptr);
	Engine *engine = new Engine(world, renderer);

	uint8_t grn[3] = {0x64, 0xDC, 0x32};
	uint8_t red[3] = {0xFF, 0x00, 0x00};
	uint8_t blu[3] = {0x00, 0x0F, 0xFF};
	engine->addBody(rect, grn);
	engine->addBody(rect1, blu);
	// engine->addBody(ellipse1, red);
	// engine->addBody(ellipse, grn);

	engine->start();

	return app.exec();
}
