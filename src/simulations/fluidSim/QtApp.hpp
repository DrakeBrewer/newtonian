#ifndef QTAPP_HPP
#define QTAPP_HPP

#include <QMainWindow>
#include <QPushButton>

class QtApp : public QMainWindow 
{ 
    Q_OBJECT

public:
    QtApp(QWidget *parent = nullptr);
    
private slots:
    //void run();

private:
    QPushButton *startButton;
};
#endif