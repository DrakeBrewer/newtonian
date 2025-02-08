#include "fluidSim.hpp"

int main(int argc, char *argv[]){
    
    cout << "Fluid Simulation\n\n";

    cout << "Enter \"help\" to see the options" << endl;

    string userInput = {};
    while(true){
        cout << "\nEnter a prompt :";
        getline(cin,userInput);

        if(userInput.compare("exit") == 0 || userInput == "q"){
            cout << "Exiting...\n";
            break;
        }
        else if(userInput == "help"){
            cout << "Prompt options\n"
                    "exit: will exit the program\n"
                    "test1: sim an object falling into water\n"
                    "test2: sim an object starting under the water\n"
                    "details: detailed explanation of each test" << endl;
            continue;
        }
        else if(userInput == "details"){
            cout << "Detailed Explanation\n"
                    "test1:\n" 
                    "   Object starts at a height of 10 meters and with a velocity of 0\n"
                    "test2:\n"
                    "   Object starts at a height of -10 meters (in the water)\n"
                    "   and a velocity of 0\n";
            continue;
        }
        else if(userInput.compare("test1") == 0){
            cout << "Don't have the sim ready yet" << endl;
            runTest1();
            continue;
        }
        else if(userInput.compare("test2") == 0){
            cout << "Don't have the sim ready yet" << endl;
            
            //simulate test2
            //runTest2();
            continue;
        }
        else{
            cout << "Not a prompt, do \"help\" for prompts" << endl;
            continue;
        }

        break;
    }

    return 0;
}


int runTest1(){
    //The top of the water level is at z=0 , everything less than 0 is water

    string input;
    int sec = 0;
    int vFin = 0;

    object obj(10);
    fluid water;

    // Will add user input to set the initial height, water level, velocity, density


    //Will need to add the real equations for gravity to get the actual values of the final
    //velocity of the object before it enters the water

    while(obj.getZ() > water.getFL()){
        obj.setZ((obj.getZ() - 9.81));
        vFin = obj.getInitV() + (9.81*sec);
        sec++;
        cout<<"Sec:" << sec << "\nObject height:" << obj.getZ()<< endl;
    }

    cout<<"Simulation Done\n";
    cout<<"Object reached the water in "<< sec << " seconds." << endl;


    return 0;
}


int runTest2(){
    
    //Not implemented yet
    //
    //Might not need it, think I can implement both into 1 test

    return 0;
}
