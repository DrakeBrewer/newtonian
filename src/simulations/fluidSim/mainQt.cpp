#include <QApplication>
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


int main(int argc, char **argv) {
	QApplication app(argc, argv);

	QGraphicsScene *scene = new QGraphicsScene();

    fluidRectangle *rect = new fluidRectangle(200, 100, Vector3d(-100, 0, -100), 100, true, 1000);
    fluidEllipse *ellipse = new fluidEllipse(Vector3d(0, 0, 20), false,  .47, 500);
	ellipse->velocity = Vector3d(0, 0, 0);

	fluidPhysicsWorld *world = new fluidPhysicsWorld(9.80665);
	// world->addBody(rect);
	// world->addBody(ellipse);

	fluidPhysicsRenderer *renderer = new fluidPhysicsRenderer(world, scene, nullptr);
	// renderer->addBody(rect, QColor(100, 220, 50));
	// renderer->addBody(ellipse, c);

	fluidEngine *engine = new fluidEngine(world, renderer);
	uint8_t blue[3] = {0x44, 0x44, 0xFF};
	uint8_t red[3] = {0xFF, 0x00, 0x00};
	engine->addBody(rect, blue);
	engine->addBody(ellipse, red);

	engine->start();

	return app.exec();
}