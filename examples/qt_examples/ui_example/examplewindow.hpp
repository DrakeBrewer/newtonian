// Boiler plate code created by Qt Creator

#ifndef EXAMPLEWINDOW_HPP
#define EXAMPLEWINDOW_HPP

#include <QMainWindow>
#include "ui_example_window.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class example_window;
}
QT_END_NAMESPACE

class example_window : public QMainWindow
{
    Q_OBJECT

public:
    example_window(QWidget *parent = nullptr);
    ~example_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::example_window *ui;
};
#endif // EXAMPLEWINDOW_HPP
