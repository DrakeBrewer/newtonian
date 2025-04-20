#include "simConfig.hpp"

using namespace std;

// Constructor declaration
simConfigWindow::simConfigWindow(QWidget *parent) : QWidget(parent){

    setWindowTitle("Configure Simulation");
    resize(1000, 1000);

    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(pal);

    layout = new QVBoxLayout(this);
    startButton = new QPushButton("Start");
    quitButton = new QPushButton("Quit");

    //Labels and Inputs
    selectPlanetLabel = new QLabel("Select Planet");

    planetSelect = new QComboBox();
    planetSelect -> addItems({"Earth","Moon","Mercury","Venus","Mars","Jupiter","Saturn","Uranus","Neptune"});

    selectObjectLabel = new QLabel("Select an object:");

    objectSelect = new QComboBox();
    objectSelect -> addItems({"Sphere"});
    
    massInput = new QLineEdit();
    massInput -> setPlaceholderText("Enter the object mass");

    initVInput = new QLineEdit();
    initVInput -> setPlaceholderText("Enter the object's initial velocity");

    xInput = new QLineEdit();
    xInput -> setPlaceholderText("Enter starting X value");

    yInput = new QLineEdit();
    yInput -> setPlaceholderText("Enter starting Y value");

    zInput = new QLineEdit();
    zInput -> setPlaceholderText("Enter starting Z value");

    xPlaneInput = new QLineEdit();
    xPlaneInput -> setPlaceholderText("Enter Plane X Position");
    
    yPlaneInput = new QLineEdit();
    yPlaneInput -> setPlaceholderText("Enter Plane Y Position");

    zPlaneInput = new QLineEdit();
    zPlaneInput -> setPlaceholderText("Enter Plane Z Position");

    //Add widgets to layout 
    layout -> addStretch();

    layout -> addWidget(selectPlanetLabel, 0, Qt::AlignCenter);
    layout -> addWidget(planetSelect, 0, Qt::AlignCenter);

    layout -> addWidget(selectObjectLabel, 0, Qt::AlignCenter);
    layout -> addWidget(objectSelect, 0, Qt::AlignCenter);
   
    layout -> addWidget(massInput, 0, Qt::AlignCenter);
    layout -> addWidget(initVInput, 0, Qt::AlignCenter);

    layout -> addWidget(xInput, 0, Qt::AlignCenter);
    layout -> addWidget(yInput, 0, Qt::AlignCenter);
    layout -> addWidget(zInput, 0, Qt::AlignCenter);

    layout -> addWidget(xPlaneInput, 0, Qt::AlignCenter);
    layout -> addWidget(yPlaneInput, 0, Qt::AlignCenter);
    layout -> addWidget(zPlaneInput, 0, Qt::AlignCenter);

    layout -> addWidget(startButton, 0, Qt::AlignCenter);
    layout -> addWidget(quitButton, 0, Qt::AlignCenter);


    layout -> addStretch();

    floatValidator = new QDoubleValidator(0.0, 1000.0,2, this);
    massInput -> setValidator(floatValidator);
    initVInput -> setValidator(floatValidator);
    xInput -> setValidator(floatValidator);
    yInput -> setValidator(floatValidator);
    zInput -> setValidator(floatValidator);
    xPlaneInput -> setValidator(floatValidator);
    yPlaneInput -> setValidator(floatValidator);
    zPlaneInput -> setValidator(floatValidator);

    connect(startButton, &QPushButton::clicked,this,&simConfigWindow::checkInputs);
    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);


    


}

void simConfigWindow::checkInputs(){

  
    if ( massInput->text().isEmpty() || initVInput->text().isEmpty()|| xInput->text().isEmpty() || zInput->text().isEmpty() 
    || yInput->text().isEmpty() || xPlaneInput->text().isEmpty() || yPlaneInput->text().isEmpty() || zPlaneInput->text().isEmpty()){
        cout<<"Checked empty inputs"<<endl;
        QMessageBox::warning(this, "Missing Inputs", "Please enter all fields.");
        return;
    }
    //cout << "All inputs were filled. Proceeding..." << endl;

    QString selectedPlanet = planetSelect -> currentText().toLower();
    QString selectedObject = objectSelect -> currentText();

    string planetName = selectedPlanet.toStdString();
    string objectNamed = selectedObject.toStdString();
    
    float mass = massInput -> text().toFloat();
    float initV = initVInput -> text().toFloat();
    float x = xInput -> text().toFloat();
    float y = yInput -> text().toFloat();
    float z = zInput -> text().toFloat();
    float planeX = xPlaneInput -> text().toFloat();
    float planeY = yPlaneInput -> text().toFloat();
    float planeZ = zPlaneInput -> text().toFloat();


    planet p(planetName);

    object obj = p.spawnObj(objectNamed);
   
    plane pl = p.spawnPlane("Plane");

    obj.setMass(mass);
    obj.setInitV(initV);
    obj.setX(x);
    obj.setY(y);
    obj.setZ(z);

    pl.setX(planeX);
    pl.setY(planeY);
    pl.setZ(planeZ);
    
    //freeFall(obj,p,pl);
    runSimulation(p.getGrav(), x, y, z, planeX,planeY,planeZ, initV, mass,planetName);



}