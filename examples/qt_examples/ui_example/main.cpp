#include "examplewindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    example_window w;
    w.show();
    return a.exec();
}
