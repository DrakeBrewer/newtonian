#include <QApplication>
#include <QPushButton>
#include <QtWidgets/qgraphicsitem.h>
#include <QtWidgets/qgraphicsscene.h>
#include <QtWidgets/qgraphicsview.h>
#include <sys/types.h>

#include "fluidRenderer.hpp"
#include "fluidBody.hpp"
#include "fluidShapes.hpp"
#include "vector3d.hpp"
#include "fluidWorld.hpp"
#include "fluidEngine.hpp"
#include "fluidPhysicsView.hpp"
void runQtSim();

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	QGraphicsScene *scene = new QGraphicsScene();

	// Text boxes
	QFont font("Arial", 2);
	QGraphicsTextItem *textItem1 = new QGraphicsTextItem;
    textItem1->setPlainText("Corn Syrup");
	textItem1->setPos(-35, 30);
    textItem1->setFont(font);
    //textItem1->setDefaultTextColor(Qt::black);
	textItem1->setTransform(QTransform().scale(1,-1));
	scene->addItem(textItem1);

	QGraphicsTextItem *textItem2 = new QGraphicsTextItem;
    textItem2->setPlainText("Water");
	textItem2->setPos(-9, 30);
    textItem2->setFont(font);
    //textItem2->setDefaultTextColor(Qt::blue);
	textItem2->setTransform(QTransform().scale(1,-1));
	scene->addItem(textItem2);

	QGraphicsTextItem *textItem3 = new QGraphicsTextItem;
    textItem3->setPlainText("Oil");
	textItem3->setPos(15, 30);
    textItem3->setFont(font);
	textItem3->setTransform(QTransform().scale(1,-1));
	scene->addItem(textItem3);

	
	// Liquids
    fluidLiquid *water = new fluidLiquid(22.222, 100, Vector3d(-11.111, 0, -100), true, 1000);
	fluidLiquid *cornSyrup = new fluidLiquid(22.222, 100, Vector3d(-33.333, 0, -100), true, 1380);
	fluidLiquid *oil = new fluidLiquid(22.222, 100, Vector3d(11.111, 0, -100), true, 800);

	// Non moving Objects
	fluidRectangle *wall1 = new fluidRectangle(2,100,Vector3d(-11.111, 0, -49), true);
	fluidRectangle *wall2 = new fluidRectangle(2,100,Vector3d(11.111, 0, -49), true);
	fluidRectangle *wall3 = new fluidRectangle(2,100,Vector3d(-33.333, 0, -49), true);
	fluidRectangle *wall4 = new fluidRectangle(2,100,Vector3d(33.333, 0, -49), true);

	// Thrown Objects
	fluidEllipse *rock1 = new fluidEllipse(Vector3d(-33.333, 0, 0), false,  .47, 2500);
	fluidEllipse *rock2 = new fluidEllipse(Vector3d(-33.333, 0, 0), false,  .47, 2500);
	fluidEllipse *rock3 = new fluidEllipse(Vector3d(-33.333, 0, 0), false,  .47, 2500);
	rock1->velocity = Vector3d(1.5, 0, 20);
	rock2->velocity = Vector3d(6, 0, 20);
	rock3->velocity = Vector3d(12, 0, 20);

	fluidEllipse *apple1 = new fluidEllipse(Vector3d(-11.111, 0, 3), false,  .47, 515.27);
	fluidEllipse *apple2 = new fluidEllipse(Vector3d(11.111, 0, 3), false,  .47, 515.27);
	fluidEllipse *apple3 = new fluidEllipse(Vector3d(33.333, 0, 3), false,  .47, 515.27);
	apple1->velocity = Vector3d(-8, 0, -2);
	apple2->velocity = Vector3d(-8, 0, -2);
	apple3->velocity = Vector3d(-8, 0, -2);


	// Sumbmerged Objects
	fluidEllipse *wood1 = new fluidEllipse(Vector3d(-13.222, 0, -30), false,  .47, 500);
	fluidEllipse *wood2 = new fluidEllipse(Vector3d(9, 0, -30), false,  .47, 500);
	fluidEllipse *wood3 = new fluidEllipse(Vector3d(31.222, 0, -30), false,  .47, 500);

	// Drag Coe difference
	fluidRectangle *box = new fluidRectangle(Vector3d(2, 0, 20), false, 1.05, 900);
	fluidEllipse *circle = new fluidEllipse(Vector3d(0, 0, 20), false,  .47, 900);
	fluidTriangle *tri = new fluidTriangle(Vector3d(4, 0, 20), false, 1, .97, 900);
	fluidTriangle *tri21 = new fluidTriangle(Vector3d(6, 0, 20), false, 2, .5, 900);

	fluidRectangle *box2 = new fluidRectangle(Vector3d(-21, 0, 20), false, 1.05, 900);
	fluidEllipse *circle2 = new fluidEllipse(Vector3d(-23, 0, 20), false,  .47, 900);
	fluidTriangle *tri2 = new fluidTriangle(Vector3d(-19, 0, 20), false, 1, .97, 900);
	fluidTriangle *tri22 = new fluidTriangle(Vector3d(-17, 0, 20), false, 2, .5, 900);

	fluidRectangle *box3 = new fluidRectangle(Vector3d(16, 0, 20), false, 1.05, 900);
	fluidEllipse *circle3 = new fluidEllipse(Vector3d(14, 0, 20), false,  .47, 900);
	fluidTriangle *tri3 = new fluidTriangle(Vector3d(18, 0, 20), false, 1, .97, 900);
	fluidTriangle *tri23 = new fluidTriangle(Vector3d(20, 0, 20), false, 2, .5, 900);


	fluidPhysicsWorld *world = new fluidPhysicsWorld(9.80665);

	fluidPhysicsRenderer *renderer = new fluidPhysicsRenderer(world, scene, nullptr);

	fluidEngine *engine = new fluidEngine(world, renderer);

	uint8_t blue[3] = {0x44, 0x44, 0xFF};
	uint8_t red[3] = {0xFF, 0x00, 0x00};
	uint8_t green[3] = {0x44, 0xFF, 0x44};
	uint8_t orange[3] = {0xFF, 0xA5, 0x00};
	uint8_t yellow[3] = {0xFF, 0xFF, 0x44};
	uint8_t cyan[3] = {0x44, 0xFF, 0xFF};
	uint8_t magenta[3] = {0xFF, 0x44, 0xFF};
	uint8_t white[3] = {0xFF, 0xFF, 0xFF};
	uint8_t black[3] = {0x00, 0x00, 0x00};
	uint8_t brown[3] = {0xed, 0xb6, 0x8c};
	uint8_t grey[3] = {0xb0, 0xb0, 0xb0};

	// Liquids
	engine->addBody(water, blue);
	engine->addBody(cornSyrup, yellow);
	engine->addBody(oil, black);

	// Non moving Objects
	engine->addBody(wall1, grey);
	engine->addBody(wall2, grey);
	engine->addBody(wall3, grey);
	engine->addBody(wall4, grey);

	// Thrown Objects
	engine->addBody(rock1, grey);
	engine->addBody(rock2, grey);
	engine->addBody(rock3, grey);

	engine->addBody(apple1, red);
	engine->addBody(apple2, red);
	engine->addBody(apple3, red);

	// Sumbmerged Objects
	engine->addBody(wood1, brown);
	engine->addBody(wood2, brown);
	engine->addBody(wood3, brown);
	
	// Drag Coe difference
	engine->addBody(box, green);
	engine->addBody(circle, green);
	engine->addBody(tri, green);
	engine->addBody(tri21, green);

	engine->addBody(box2, green);
	engine->addBody(circle2, green);
	engine->addBody(tri2, green);
	engine->addBody(tri22, green);

	engine->addBody(box3, green);
	engine->addBody(circle3, green);
	engine->addBody(tri3, green);
	engine->addBody(tri23, green);

	//--------------------


	// Create the view
	QGraphicsView *view = new QGraphicsView(scene);
	view->setRenderHint(QPainter::Antialiasing);
	view->setWindowTitle("Fluid Simulation");
	view->resize(800, 600);

	// Create Start button
	QPushButton *startButton = new QPushButton("Start Simulation", view);
	startButton->move(0, 10); 
	startButton->resize(150, 30);

	// Connect button signal to engine start
	QObject::connect(startButton, &QPushButton::clicked, engine, &fluidEngine::start);

	// Create Stop button
	QPushButton *stopButton = new QPushButton("Stop Simulation", view);
	stopButton->move(160, 10);  
	stopButton->resize(150, 30);

	// Connect button signal to engine start
	QObject::connect(stopButton, &QPushButton::clicked, engine, &fluidEngine::stop);

	view->show();

	return app.exec();



	//engine->start();

	//return app.exec();
}