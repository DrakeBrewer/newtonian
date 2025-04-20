
#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QPalette>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QListWidget>
#include <QMessageBox>
#include <string>
#include <QGraphicsProxyWidget>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QImageReader>



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
#include "simulation.hpp"


void runSimulation(float grav, float x, float y, float z,float xPLane, float yPlane, float zPlane, float initV, float mass,string planetName) {
    QGraphicsScene *scene = new QGraphicsScene();

    Rectangle *rect = new Rectangle(5000, 50, Vector3d(xPLane, yPlane, zPlane), 100, true);
    Ellipse *ellipse = new Ellipse(20, Vector3d(x, y, z), mass, false);
    ellipse->velocity = Vector3d(0, 0, initV);

    PhysicsWorld *world = new PhysicsWorld(grav);
    PhysicsRenderer *renderer = new PhysicsRenderer(world, scene, nullptr);

    //Button for qutiting the window
    QPushButton *quitButton = new QPushButton("Quit");
    quitButton->setFixedSize(120, 100);

    QFont font = quitButton->font();
    font.setPointSize(18);
    quitButton->setFont(font);

    QObject::connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);

    QGraphicsProxyWidget *proxy = scene->addWidget(quitButton);
    proxy->setTransform(QTransform::fromScale(1, -1), true);  // Flip upright
    proxy->setPos(600, 750);  // Adjust Y to account for flip

    //Set a background image
    QString bgPath = QString("C:/Users/tboen/OneDrive/Documents/PhysicsEngine/DrakeBrewer/newtonian/src/simulations/planetSim/resources/%1.jpeg").arg(QString::fromStdString(planetName));
    QPixmap bgPixmap(bgPath);
    bgPixmap = bgPixmap.transformed(QTransform().scale(1, -1));
    bgPixmap = bgPixmap.scaled(
        scene->sceneRect().size().toSize(),
        Qt::IgnoreAspectRatio,   
        Qt::SmoothTransformation
    );
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem(bgPixmap);
    background->setZValue(-1); // Push it to the background
    background->setPos(scene->sceneRect().topLeft());
    scene->addItem(background);

    Engine *engine = new Engine(world, renderer);

    // Change the colors based on the planet
    if (planetName == "earth") {
        uint8_t color[3] = {0x00, 0x64, 0x00}; // dark green
        engine->addBody(rect, color);
    } 
    else if (planetName == "moon") {
        uint8_t color[3] = {0xA9, 0xA9, 0xA9}; // grey
        engine->addBody(rect, color);
    } 
    else if (planetName == "mercury") {
        uint8_t color[3] = {0x80, 0x80, 0x80}; // darker grey
        engine->addBody(rect, color);
    } 
    else if (planetName == "venus") {
        uint8_t color[3] = {0xD2, 0xB4, 0x8C}; // tan/brownish
        engine->addBody(rect, color);
    } 
    else if (planetName == "mars") {
        uint8_t color[3] = {0xB2, 0x22, 0x22}; // red
        engine->addBody(rect, color);
    } 
    else if (planetName == "jupiter") {
        uint8_t color[3] = {0xCD, 0x85, 0x3F}; // brownish-orange
        engine->addBody(rect, color);
    } 
    else if (planetName == "saturn") {
        uint8_t color[3] = {0xDA, 0xC1, 0x76}; // pale gold
        engine->addBody(rect, color);
    } 
    else if (planetName == "uranus") {
        uint8_t color[3] = {0xAF, 0xEE, 0xEE}; // light cyan
        engine->addBody(rect, color);
    } 
    else if (planetName == "neptune") {
        uint8_t color[3] = {0x00, 0x00, 0x8B}; // deep blue
        engine->addBody(rect, color);
    } 
    else {
        uint8_t color[3] = {0x64, 0x64, 0x64}; // default: gray
        engine->addBody(rect, color);
    }

    uint8_t red[3] = {0xFF, 0x00, 0x00};
    engine->addBody(ellipse, red);

    engine->start();
}
