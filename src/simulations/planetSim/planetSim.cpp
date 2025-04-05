
// #include "planets.hpp"
// #include "QtApp.hpp"
// #include "simConfig.hpp"

#include <QApplication>
#include <QMainWindow>
#include <QComboBox>
#include <QVBoxLayout>
#include <QDebug>

int main(int argc, char *argv[]){
    
    //QCoreApplication::addLibraryPath("C:/Qt/6.8.2/mingw_64/plugins");
    //QCoreApplication::addLibraryPath("platforms");
    //QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath() + "/platforms");

    // QApplication app(argc, argv);//Initalize the QT event loop

    // QCoreApplication::addLibraryPath(QCoreApplication::applicationDirPath() + "/platforms");
    
    // QtApp mainWindow;//Create an instance of the mainwindow
    // mainWindow.show();//Display the window

    // return app.exec();//Start the app

    QApplication app(argc, argv);

    QMainWindow window;
    QWidget *central = new QWidget(&window);
    QVBoxLayout *layout = new QVBoxLayout(central);

    QComboBox *combo = new QComboBox(central);
    combo->addItems({"Earth", "Mars", "Venus"});
    layout->addWidget(combo);

    QObject::connect(combo, &QComboBox::currentTextChanged, [](const QString &text){
        qDebug() << "Selected:" << text;
    });

    window.setCentralWidget(central);
    window.setWindowTitle("Combo Test");
    window.resize(400, 200);
    window.show();

    return app.exec();

    

};

// int planetSim(){
//     // string userIn;

//     // cout<<"Welcome To Planet Sim."<<endl;

//     // cout<<"Enter 'H' for a help menu / command list"<<endl;//TODO: Add help menu

//     // while(true){

//     //     cout<<"Where would you like to run the simulation?"<<endl;

//     //     getline(cin,userIn);//TODO: Make user input more robust

//     //     if(userIn == "exit"){

//     //         cout<<"Goodbye"<<endl;
//     //         return 0;
//     //     }
            
//     //     else if(userIn == "earth"){

//     //         cout<<"Earth Selected"<<endl;

//     //         cout<<"Setting Up Sim...."<<endl;

//     //         planet p("Earth",9.81);

//     //         setSim(p);
    
//     //     }
//     //     else if(userIn == "moon"){
            
//     //         cout<<"Moon Selected"<<endl;

//     //         cout<<"Setting Up Sim...."<<endl;

//     //         planet p("Moon",1.62);

//     //         setSim(p);
//     //     }

//     //     else if(userIn == "mercury"){

//     //         cout<<"Mercury Selected"<<endl;

//     //         cout<<"Setting Up Sim...."<<endl;

//     //         planet p("Mercury",3.7);

//     //         setSim(p);
//     //     }

//     //     else if(userIn == "venus"){

//     //         cout<<"Venus Selected"<<endl;

//     //         cout<<"Setting Up Sim...."<<endl;

//     //         planet p("Venus",8.87);

//     //         setSim(p);
//     //     }

//     //     else if(userIn == "mars"){

//     //         cout<<"mars Selected"<<endl;

//     //         cout<<"Setting Up Sim...."<<endl;

//     //         planet p("mars",3.73);

//     //         setSim(p);
//     //     }

//     //     else if(userIn == "jupiter"){

//     //         cout<<"Jupiter Selected"<<endl;

//     //         cout<<"Setting Up Sim...."<<endl;

//     //         planet p("Jupiter",24.79);

//     //         setSim(p);
//     //     }

//     //     else if(userIn == "saturn"){

//     //         cout<<"Saturn Selected"<<endl;

//     //         cout<<"Setting Up Sim...."<<endl;

//     //         planet p("Saturn",10.44);

//     //         setSim(p);
//     //     }

//     //     else if(userIn == "uranus"){

//     //         cout<<"Uranus Selected"<<endl;

//     //         cout<<"Setting Up Sim...."<<endl;

//     //         planet p("Uranus",8.87);

//     //         setSim(p);
//     //     }

//     //     else if(userIn == "neptune"){

//     //         cout<<"Neptune Selected"<<endl;

//     //         cout<<"Setting Up Sim...."<<endl;

//     //         planet p("Neptune",11.15);

//     //         setSim(p);
//     //     }

//     //     else{

//     //         cout<<"Error: Unidentified Input: "<<userIn <<endl;
//     //     }
//     // }

//     return 0;

// }

// int setSim(planet p){

//     string input;

//     cout<<"What object would you like to spawn?"<<endl;

//     getline(cin,input);
    
//     if(input != "sphere") cout<<"Invalid object"<<input<<endl;//TODO: Add more options for object spawns

//     object obj = p.spawnObj(input);

//     cout<<"Please set the object's initial position"<<endl;

//     cout<<"X:";

//     getline(cin,input);

//     obj.setX(stof(input));

//     cout<<"Y:";

//     getline(cin,input);

//     obj.setY(stof(input));

//     cout<<"Z:";

//     getline(cin,input);

//     obj.setZ(stof(input));

//     cout<<"Your input was "<<obj.getX()<<obj.getY()<<obj.getZ()<<endl;

//     cout<<"Please set the objects mass"<<endl;

//     getline(cin,input);

//     cout<<"Your input was "<<input<<endl;

//     obj.setMass(stof(input));

//     cout<<"Please set the objects initial velocity"<<endl;

//     getline(cin,input);

//     cout<<"Your input was "<<input<<endl;

//     obj.setInitV(stof(input));

//     cout<< "Please indicate the plane positions"<<endl;

//     plane pl = p.spawnPlane("plane1");

//     cout<< "X:";

//     getline(cin,input);

//     cout<<"Your input was "<<input<<endl;

//     pl.setX(stof(input));

//     cout<< "Y:";

//     getline(cin,input);

//     cout<<"Your input was "<<input<<endl;

//     pl.setY(stof(input));

//     cout<< "Z:";

//     getline(cin,input);

//     cout<<"Your input was "<<input<<endl;

//     pl.setZ(stof(input));

//     cout << "What simulation would you like to run?" <<endl;

//     getline(cin,input);

//     if(input == "free fall"){

//         cout << "Running Sim" <<endl;

//         freeFall(obj, p, pl);

//     }

//     return 0;

// }

// int freeFall(object obj, planet p, plane pl){//Free fall simulation
    
//     //Vars I will need
//     float vFin = 0;
//     int sec = 0;
//     int time = 0;

//     string input;

//     //Get user input
//     cout<<"Please set free fall time"<<endl;

//     getline(cin,input);

//     cout<<"Your input was "<<time<<endl;

//     time = stoi(input);

//     while(sec != time){//Free fall loop

//         obj.setY((obj.getY()) - (p.getGrav()));

//         if((obj.getY()) <= (pl.getX())){

//             cout<<"Object Reached Plane"<<endl;
//             break;
//         }

//         obj.printPos();

//         vFin = (obj.getInitV()) + ((p.getGrav())*sec);

//         cout<<"Velocity: "<<vFin<<"At time: "<<sec<<endl;

//         sec++;

//     }
//     cout<<"Simulation Completed"<<endl;

//     cout<<"Final Velocity: "<<vFin<<endl;

//     cout<<"Final Position:"<< endl;
//     obj.printPos();

//     return 0;

// }
