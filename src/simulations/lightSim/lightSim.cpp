#include <QApplication>
#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsscene.h>
#include <QtWidgets/qgraphicsview.h>
#include <qvariant.h>
#include <sys/types.h>
#include <iostream>

#include "renderer.hpp"
#include "rigidBody.hpp"
#include "shapes.hpp"
#include "vector3d.hpp"
#include "world.hpp"
#include "engine.hpp"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	QGraphicsScene *scene = new QGraphicsScene();

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

	int triWidth = 50;
	int triHeight = 20;
	float triMass = 1.0f;
	Triangle *mirror1 = new Triangle(triWidth,triHeight, Vector3d(0,0,-100), 1.0f, true);
	Triangle *mirror2 = new Triangle(triWidth,triHeight, Vector3d(50,0,0), 1.0f, true);
	Triangle *mirror3 = new Triangle(triWidth,triHeight, Vector3d(0,0,100), 1.0f, true);
	Triangle *mirror4 = new Triangle(triWidth,triHeight, Vector3d(-50,0,0), 1.0f, true);
	Triangle *mirror5 = new Triangle(triWidth,triHeight, Vector3d(-100,0,-100), 1.0f, true);
	Triangle *mirror6 = new Triangle(triWidth,triHeight, Vector3d(100,0,-100), 1.0f, true);
	Triangle *mirror7 = new Triangle(triWidth,triHeight, Vector3d(100,0,100), 1.0f, true);
	Triangle *mirror8 = new Triangle(triWidth,triHeight, Vector3d(-100,0,100), 1.0f, true);

	//Rectangle *mirror = new Rectangle(10, 1, Vector3d(0,0,0), 1.0f, true);
	engine->addBody(mirror1, cyan);
	engine->addBody(mirror2, cyan);
	engine->addBody(mirror3, cyan);
	engine->addBody(mirror4, cyan);
	engine->addBody(mirror5, cyan);
	engine->addBody(mirror6, cyan);
	engine->addBody(mirror7, cyan);
	engine->addBody(mirror8, cyan);


	Rectangle *mirrorU = new Rectangle(250, 50, Vector3d(0,0,180), 1.0f, true);
	Rectangle *mirrorD = new Rectangle(250, 50, Vector3d(0,0,-180), 1.0f, true);
	Rectangle *mirrorL = new Rectangle(50, 250, Vector3d(-180,0,0), 1.0f, true);
	Rectangle *mirrorR = new Rectangle(50, 250, Vector3d(180,0,0), 1.0f, true);
	engine->addBody(mirrorU, blue);
	engine->addBody(mirrorD, blue);
	engine->addBody(mirrorL, blue);
	engine->addBody(mirrorR, blue);

	Ellipse *sun = new Ellipse(10, Vector3d(0,0,40), 1.0f, true);
	Ellipse *moon = new Ellipse(10, Vector3d(0,0,-40), 1.0f, true);
	engine->addBody(sun, yellow);
	engine->addBody(moon, magenta); 

	LightBody *ray1 = new LightBody(Vector3d(0,0,0), Vector3d(0,0,-1), 500e-9f);
	LightBody *ray2 = new LightBody(Vector3d(0,0,0), Vector3d(0,0,1), 500e-9f);
	LightBody *ray3 = new LightBody(Vector3d(0,0,0), Vector3d(1,0,-1), 500e-9f);
	LightBody *ray4 = new LightBody(Vector3d(0,0,0), Vector3d(-1,0,-1), 500e-9f);
	LightBody *ray5 = new LightBody(Vector3d(0,0,0), Vector3d(-1,0,1), 500e-9f);
	LightBody *ray6 = new LightBody(Vector3d(0,0,0), Vector3d(2,0,-1), 500e-9f);
	LightBody *ray7 = new LightBody(Vector3d(0,0,0), Vector3d(0,0,-2), 500e-9f);
	LightBody *ray8 = new LightBody(Vector3d(0,0,0), Vector3d(2,0,1), 500e-9f);
	LightBody *ray9 = new LightBody(Vector3d(0,0,0), Vector3d(1,0,2), 500e-9f);
	LightBody *ray10 = new LightBody(Vector3d(0,0,0), Vector3d(1,0,1), 500e-9f);
	LightBody *ray11 = new LightBody(Vector3d(1,0,0), Vector3d(3,0,-1), 500e-9f);
	LightBody *ray12 = new LightBody(Vector3d(1,0,1), Vector3d(3,0,-2), 500e-9f);
	LightBody *ray13 = new LightBody(Vector3d(0,0,1), Vector3d(-3,0,5), 500e-9f);
	LightBody *ray14 = new LightBody(Vector3d(2,0,1), Vector3d(1,0,0), 500e-9f);
	LightBody *ray15 = new LightBody(Vector3d(2,0,2), Vector3d(0,0,-2), 500e-9f);
	LightBody *ray16 = new LightBody(Vector3d(0,0,2), Vector3d(4,0,2), 500e-9f);
	LightBody *ray17 = new LightBody(Vector3d(-1,0,0), Vector3d(1,0,9), 500e-9f);
	LightBody *ray18 = new LightBody(Vector3d(1,0,-1), Vector3d(-1,0,-9), 500e-9f);
	LightBody *ray19 = new LightBody(Vector3d(0,0,1), Vector3d(2,0,2), 500e-9f);
	LightBody *ray20 = new LightBody(Vector3d(-3,0,0), Vector3d(-3,0,2), 500e-9f);
	LightBody *ray21 = new LightBody(Vector3d(0,0,1), Vector3d(3,0,-2), 500e-9f);
	engine->addBody(ray1, red);
	engine->addBody(ray2, red);
	engine->addBody(ray3, red);
	engine->addBody(ray4, red);
	engine->addBody(ray5, red);
	engine->addBody(ray6, red);
	engine->addBody(ray7, red);
	engine->addBody(ray8, red);
	engine->addBody(ray9, red);
	engine->addBody(ray10, red);
	engine->addBody(ray12, red);
	engine->addBody(ray13, red);
	engine->addBody(ray14, red);
	engine->addBody(ray15, red);
	engine->addBody(ray16, red);
	engine->addBody(ray17, red);
	engine->addBody(ray18, red);
	engine->addBody(ray19, red);
	engine->addBody(ray20, red);
	engine->addBody(ray21, red);

	engine->start();

	app.exec();

	std::cout << "\n";
	return 0;
}
