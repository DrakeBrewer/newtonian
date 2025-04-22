#include <QWheelEvent>
#include <QtWidgets/qgraphicsview.h>

#include "fluidPhysicsView.hpp"

void fluidPhysicsView::wheelEvent(QWheelEvent *e) {
	if (e->modifiers() & Qt::ControlModifier) {
		int delta = e->angleDelta().y();
		if (delta > 0) {
			scale(1.02, 1.02);
		} else {
			scale(1/1.02, 1/1.02);
		}

		e->accept();
	} else {
		QGraphicsView::wheelEvent(e);
	}
}