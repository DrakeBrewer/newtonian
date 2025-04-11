#include <QGraphicsView>
#include <QWheelEvent>

class PhysicsView : public QGraphicsView {
public:
	PhysicsView(QGraphicsScene *scene = nullptr, QWidget *parent = nullptr) : QGraphicsView(scene, parent) {};
protected:
	void wheelEvent(QWheelEvent *e);
};
