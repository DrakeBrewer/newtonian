
#include "planetSim.h"

int main(int argc, char* argv[]){

    string userIn ="";

    cout<<"Welcome To Planet Sim."<<endl;
    cout<<"Enter 'H' for a help menu / command list"<<endl;//TODO: Add help menu

    while(true){

        cout<<"What simluation would you like to run?"<<endl;

        getline(cin,userIn);//TODO: Make user input more robust

        if(userIn == "exit"){
            cout<<"Goodbye"<<endl;
            return 0;
        }
        else if(userIn == "free fall"){
            cout<< "Free fall Simulation Selected"<<endl;
            cout<<"What planet would you like to run the simulation on?"<<endl;
            
            getline(cin,userIn);
            if(userIn == "exit"){
                cout<<"Exiting Menu"<<endl;
                break;
            }
            else if(userIn == "earth"){
                cout<<"Earth Selected"<<endl;
                cout<<"Loading Sim"<<endl;
                runSim(9.81);
        
            }

        }
        else{
            cout<<"Error: Unidentified Input: "<<userIn <<endl;
        }
    }

    return 0;

}

int runSim(float grav){
    string x;
    string y;
    string z;
    string m;
    string input;
    string initV;
    string time;
    int sec = 0;
    int vFin = 0;

    cout<<"What object would you like to spawn?"<<endl;
    getline(cin,input);
    
    if(input != "sphere") cout<<"Invalid object"<<input<<endl;

    object obj(input);

    cout<<"Please set the object's initial position"<<endl;
    cout<<"X:";
    getline(cin,x);
    cout<<"Y:";
    getline(cin,y);
    cout<<"Z:";
    getline(cin,z);
    cout<<"Your input was "<<x<<y<<z<<endl;

    obj.setX(stof(x));
    obj.setY(stof(y));
    obj.setZ(stof(z));

    cout<<"Please set the objects mass"<<endl;
    getline(cin,m);
    cout<<"Your input was "<<m<<endl;
    obj.setMass(stof(m));

    cout<<"Please set the objects initial velocity"<<endl;
    getline(cin,initV);
    cout<<"Your input was "<<initV<<endl;

    cout<<"Please set free fall time"<<endl;
    getline(cin,time);
    cout<<"Your input was "<<time<<endl;

    //obj.printInfo();

    while(sec != stoi(time)){
        obj.setX((stof(x)-9.81));
        obj.printPos();
        vFin = obj.getInitV() + (9.81*sec);
        cout<<"Velocity: "<<vFin<<"At time: "<<sec<<endl;
        sec++;

    }
    cout<<"Simulation Completed"<<endl;
    cout<<"Final Velocity: cl"<<vFin<<endl;



    return 0;

}