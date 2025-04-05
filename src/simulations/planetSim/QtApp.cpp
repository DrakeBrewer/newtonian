#include "QtApp.hpp"
#include "planets.hpp"


QtApp::QtApp(QWidget *parent) : QMainWindow(parent){

    //Title and initial size
    setWindowTitle("PlanetSim");
    resize(600,600);

    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::blue);
    setAutoFillBackground(true);
    setPalette(pal);

    // Central widget & layout
    centralWidget = new QWidget(this);
    layout = new QVBoxLayout();

    // Buttons
    startButton = new QPushButton("Start");
    quitButton = new QPushButton("Quit");

    // Add buttons to layout
    layout->addStretch();  // Spacer for vertical centering
    layout->addWidget(startButton, 0, Qt::AlignCenter);
    layout->addWidget(quitButton, 0, Qt::AlignCenter);
    layout->addStretch();  // Spacer below

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    QComboBox *planetBox = new QComboBox(this);
    planetBox->addItems({"Earth", "Mars", "Jupiter"});
    planetBox->move(100, 50);
    planetBox->show();

    // Connect signals
    connect(startButton, &QPushButton::clicked, this, &QtApp::startApp);
    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    



}

void QtApp::startApp(){

    // configWindow = new simConfigWindow(this);
    // configWindow -> show();
    //qDebug() << "Qdug working";
    cout<<("Staring sim")<<endl;
    return;
}



