#include "MainWindow.hpp"
#include <QApplication>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setWindowTitle("Orbital Mechanics Simulator");
    resize(1000,800);

    // Central widget, vertical and horizontal layout
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *topLayout = new QHBoxLayout();

    // From this dropdown of planets in the Solar System, the user can select a planet
    QComboBox *planetDropdown = new QComboBox(centralWidget);

    planetDropdown->setMinimumWidth(87);

    planetDropdown->setStyleSheet("QComboBox{ font-size: 20pt; font-weight: bold; }");

    planetDropdown->addItem("Planets");
    planetDropdown->addItem("Mercury");
    planetDropdown->addItem("Venus");
    planetDropdown->addItem("Earth");
    planetDropdown->addItem("Mars");
    planetDropdown->addItem("Jupiter");
    planetDropdown->addItem("Saturn");
    planetDropdown->addItem("Uranus");
    planetDropdown->addItem("Neptune");
    
    planetDropdown->setCurrentIndex(0);

    connect(planetDropdown, &QComboBox::currentTextChanged, this, &MainWindow::planetSelected);

    topLayout->addWidget(planetDropdown, 0, Qt::AlignLeft);
    topLayout->addStretch();
    
    mainLayout->addLayout(topLayout);
    mainLayout->addStretch();
}

MainWindow::~MainWindow(){

}

void MainWindow::planetSelected(const QString &planet){
    if(planet == "Planets"){
        qDebug() << "Please select a planet from the dropdown menu.";
        return;
    }

    qDebug() << "Selected planet: " << planet;
}