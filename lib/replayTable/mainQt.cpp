#include "QtApp.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ReplayTableWidget w;
    w.show();
    return a.exec();
}
