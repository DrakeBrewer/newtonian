
#include "planets.hpp"
#include "objects.hpp"

int planetSim(){

    string userIn;

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

                cout<<"Loading Sim...."<<endl;

                planet p("Earth",9.81);

                runSim(p);
        
            }
            else if(userIn == "moon"){
                cout<<"Moon Selected"<<endl;

                cout<<"Loading Sim...."<<endl;

                planet p("Moon",1.62);

                runSim(p);
            }

        }
        else{
            cout<<"Error: Unidentified Input: "<<userIn <<endl;
        }
    }

    return 0;

}

int runSim(planet p){

    string input;
    string initV;
    string time;
    int sec = 0;
    int vFin = 0;

    cout<<"What object would you like to spawn?"<<endl;

    getline(cin,input);
    
    if(input != "sphere") cout<<"Invalid object"<<input<<endl;//TODO: Add more options for object spawns

    object obj = p.spawnObj(input);

    cout<<"Please set the object's initial position"<<endl;

    cout<<"X:";

    getline(cin,input);

    obj.setX(stof(input));

    cout<<"Y:";

    getline(cin,input);

    obj.setY(stof(input));

    cout<<"Z:";

    getline(cin,input);

    obj.setZ(stof(input));

    cout<<"Your input was "<<obj.getX()<<obj.getY()<<obj.getZ()<<endl;

    cout<<"Please set the objects mass"<<endl;

    getline(cin,input);

    cout<<"Your input was "<<input<<endl;

    obj.setMass(stof(input));

    cout<<"Please set the objects initial velocity"<<endl;

    getline(cin,input);

    cout<<"Your input was "<<input<<endl;

    obj.setInitV(stof(input));

    cout<<"Please set free fall time"<<endl;

    getline(cin,time);

    cout<<"Your input was "<<time<<endl;

    //obj.printInfo();

    while(sec != stoi(time)){

        obj.setX((obj.getY() - p.getGrav()));
        obj.printPos();
        vFin = obj.getInitV() + (p.getGrav()*sec);

        cout<<"Velocity: "<<vFin<<"At time: "<<sec<<endl;

        sec++;

    }
    cout<<"Simulation Completed"<<endl;
    cout<<"Final Velocity: "<<vFin<<endl;

    return 0;

}