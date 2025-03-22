// Code Sourced from QT Widgets Tutorial - Creating a Window
// https://doc.qt.io/qt-6/qtwidgets-tutorials-widgets-toplevel-example.html
// Creates a 320x240 window called toplevel
#include <QtWidgets>
#include <QApplication>
#include <QWidget>

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.resize(320,240);
    window.show();
    window.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget"));
    return app.exec();
}
