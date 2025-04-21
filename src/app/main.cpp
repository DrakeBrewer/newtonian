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

	Rectangle *floor = new Rectangle(800, 50, Vector3d(0, 0, 0), 0, true);
	Rectangle *ceil = new Rectangle(800, 50, Vector3d(0, 0, 850), 100, true);
	Rectangle *wall1 = new Rectangle(50, 800, Vector3d(-375, 0, 425), 0, true);
	Rectangle *wall2 = new Rectangle(50, 800, Vector3d(375, 0, 425), 0, true);

	Triangle *tri = new Triangle(50, 50, Vector3d(0, 0, 250), 5, false);
	tri->velocity = Vector3d(0, 0, 0);
	Rectangle *rect = new Rectangle(50, 50, Vector3d(25, 0, 400), 20, false);
	rect->velocity = Vector3d(0, 0, 0);

	Rectangle *rect1 = new Rectangle(40, 40, Vector3d(-200, 0, 300), 15, false);
	rect1->velocity = Vector3d(120, 0, -80);

	Rectangle *rect2 = new Rectangle(60, 60, Vector3d(150, 0, 200), 25, false);
	rect2->velocity = Vector3d(-90, 0, 70);

	Triangle *tri1 = new Triangle(45, 45, Vector3d(100, 0, 500), 10, false);
	tri1->velocity = Vector3d(-110, 0, -60);

	Rectangle *rect3 = new Rectangle(35, 35, Vector3d(-150, 0, 600), 8, false);
	rect3->velocity = Vector3d(80, 0, -130);

	Triangle *tri2 = new Triangle(55, 55, Vector3d(-50, 0, 350), 12, false);
	tri2->velocity = Vector3d(70, 0, 90);

	Rectangle *rect4 = new Rectangle(45, 45, Vector3d(300, 0, 650), 18, false);
	rect4->velocity = Vector3d(-140, 0, -50);

	Triangle *tri3 = new Triangle(40, 40, Vector3d(-280, 0, 180), 7, false);
	tri3->velocity = Vector3d(60, 0, 110);

	Rectangle *rect5 = new Rectangle(50, 50, Vector3d(200, 0, 750), 22, false);
	rect5->velocity = Vector3d(-70, 0, -120);

	// Ellipse *ellipse = new Ellipse(50, Vector3d(1000, 0, -950), 5, false);
	// int i = 1000;
	// ellipse->velocity = Vector3d(-i, 0, i);
	// Ellipse *ellipse1 = new Ellipse(100, Vector3d(0, 0, 0), 5, true);

	PhysicsWorld *world = new PhysicsWorld(0.0f);
	PhysicsRenderer *renderer = new PhysicsRenderer(world, scene, nullptr);
	Engine *engine = new Engine(world, renderer);

	uint8_t grn[3] = {0x64, 0xDC, 0x32};
	uint8_t red[3] = {0xFF, 0x00, 0x00};
	uint8_t blu[3] = {0x00, 0x0F, 0xFF};
	uint8_t green[3] = {0x44, 0xFF, 0x44};
	uint8_t blue[3] = {0x44, 0x44, 0xFF};
	uint8_t orange[3] = {0xFF, 0xA5, 0x00};
	uint8_t yellow[3] = {0xFF, 0xFF, 0x44};
	uint8_t cyan[3] = {0x44, 0xFF, 0xFF};
	uint8_t magenta[3] = {0xFF, 0x44, 0xFF};
	uint8_t white[3] = {0xFF, 0xFF, 0xFF};

	engine->addBody(floor, grn);
	engine->addBody(ceil, grn);
	engine->addBody(wall1, grn);
	engine->addBody(wall2, grn);

	engine->addBody(tri, red);
	engine->addBody(rect, blu);
	engine->addBody(rect1, green);
	engine->addBody(rect2, orange);
	engine->addBody(tri1, cyan);
	engine->addBody(rect3, magenta);
	engine->addBody(tri2, yellow);
	engine->addBody(rect4, red);
	engine->addBody(tri3, blue);
	engine->addBody(rect5, green);

	engine->start();

	return app.exec();
}
