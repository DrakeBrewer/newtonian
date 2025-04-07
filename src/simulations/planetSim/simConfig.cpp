#include "simConfig.hpp"

using namespace std;

simConfigWindow::simConfigWindow(QWidget *parent) : QWidget(parent){

    setWindowTitle("Configure Simulation");
    resize(2000,2000);

    QPalette pal = palette();
    pal.setColor(QPalette::Window,Qt::blue);
    setAutoFillBackground(true);
    setPalette(pal);

    startButton = new QPushButton("Start",this);
    startButton -> move(400,50);

    connect(startButton, &QPushButton::clicked, this, &simConfigWindow::checkInputs);

    quitButton = new QPushButton("Quit",this);
    quitButton -> move(400,100);

    connect(quitButton,&QPushButton::clicked,this, &QApplication::quit);

    selectPlanetLabel = new QLabel("Select Planet",this);
    selectPlanetLabel -> move(350,200);

    planetInput = new QLineEdit(this);
    planetInput->setPlaceholderText("Enter planet name");
    planetInput->move(350, 250);

    objectInput = new QLineEdit(this);
    objectInput -> setPlaceholderText("Enter the object");
    objectInput -> move(350,400 );

    massInput = new QLineEdit(this);
    massInput -> setPlaceholderText("Enter the object mass");
    massInput -> move(600, 500);

    initVInput = new QLineEdit(this);
    initVInput -> setPlaceholderText("Enter the objects initial velocity");
    initVInput -> move(600,550);

    xInput = new QLineEdit(this);
    xInput -> setPlaceholderText("Enter starting X value");
    xInput -> move(250, 500);

    yInput = new QLineEdit(this);
    yInput -> setPlaceholderText("Enter starting Y value");
    yInput -> move(250, 550);

    zInput = new QLineEdit(this);
    zInput -> setPlaceholderText("Enter Starting Z value");
    zInput -> move(250, 600);

    floatValidator = new QDoubleValidator(0.0f, 1000.0f,2, this);
    massInput -> setValidator(floatValidator);
    initVInput -> setValidator(floatValidator);
    xInput->setValidator(floatValidator);
    yInput->setValidator(floatValidator);
    zInput->setValidator(floatValidator);


    


}

void simConfigWindow::checkInputs(){

  
    if (planetInput->text().isEmpty() || objectInput->text().isEmpty() || massInput->text().isEmpty() || initVInput->text().isEmpty()
    || xInput->text().isEmpty() || zInput->text().isEmpty() || yInput->text().isEmpty()){
        cout<<"Checked empty inputs"<<endl;
        QMessageBox::warning(this, "Missing Inputs", "Please enter all fields.");
        return;
    }
    std::cout << "All inputs were filled. Proceeding..." << std::endl;


    
    QString planetIn = planetInput -> text().trimmed().toLower();
    QString objectIn = objectInput -> text().trimmed().toLower();

    QStringList validPlanets = {"earth","moon","mercury","venus","mars","jupiter","saturn","uranus","neptune"};

    if(!validPlanets.contains(planetIn)){
        QMessageBox::warning (this,"Invalid Planet","Please enter a valid planet");
        planetInput -> clear();
        planetInput -> setFocus();
        return;
    }

    string objectName = objectIn.toStdString();
    string validPlanet = planetIn.toStdString();

    float mass = massInput -> text().toFloat();
    float initV = initVInput -> text().toFloat();
    float x = xInput -> text().toFloat();
    float y = yInput -> text().toFloat();
    float z = zInput -> text().toFloat();

    planet p(validPlanet);

    object obj = p.spawnObj(objectName);
    obj.setMass(mass);
    obj.setInitV(initV);
    obj.setX(x);
    obj.setY(y);
    obj.setZ(z);

}