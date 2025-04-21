
#include "planets.hpp"
#include "QtApp.hpp"
#include "simConfig.hpp"

#include <QApplication>
#include <QMainWindow>
#include <QComboBox>
#include <QVBoxLayout>
#include <QDebug>

int main(int argc, char *argv[]){
    
    QApplication app(argc, argv);//Initalize the QT event loop
    
    QtApp mainWindow;//Create an instance of the mainwindow
    mainWindow.show();//Display the window

    return app.exec();//Start the app

    
};



int freeFall(object obj, planet p, plane pl){//Free fall simulation
    
    //Vars I will need
    float vFin = 0;
    int sec = 0;
    int time = 0;

    string input;

    //Get user input
    // cout<<"Please set free fall time"<<endl;

    // getline(cin,input);

    // cout<<"Your input was "<<time<<endl;

    time = 60;

    while(sec != time){//Free fall loop

        obj.setY((obj.getY()) - (p.getGrav()));

        if((obj.getY()) <= (pl.getX())){

            cout<<"Object Reached Plane"<<endl;
            obj.setY(pl.getY());
            break;
        }

        obj.printPos();

        vFin = (obj.getInitV()) + ((p.getGrav())*sec);

        cout<<"Velocity: "<<vFin<<"At time: "<<sec<<endl;

        sec++;

    }
    cout<<"Simulation Completed"<<endl;

    cout<<"Final Velocity: "<<vFin<<endl;

    cout<<"Final Position:"<< endl;
    obj.printPos();

    return 0;

}
