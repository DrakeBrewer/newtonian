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

	Rectangle *rect = new Rectangle(5000, 50, Vector3d(0, 0, 0), 100, true);
	Ellipse *ellipse = new Ellipse(20, Vector3d(0, 0, 250), 5, false);
	ellipse->velocity = Vector3d(50, 0, 500);

	PhysicsWorld *world = new PhysicsWorld(9.81);
	// world->addBody(rect);
	// world->addBody(ellipse);

	PhysicsRenderer *renderer = new PhysicsRenderer(world, scene, nullptr);
	// renderer->addBody(rect, QColor(100, 220, 50));
	// renderer->addBody(ellipse, c);

	Engine *engine = new Engine(world, renderer);
	uint8_t grn[3] = {0x64, 0xDC, 0x32};
	uint8_t red[3] = {0xFF, 0x00, 0x00};
	engine->addBody(rect, grn);
	engine->addBody(ellipse, red);

	engine->start();

	return app.exec();
}
