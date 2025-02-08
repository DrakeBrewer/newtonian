#include "fluidSim.h"

int main(int argc, char *argv[]){
    
    cout << "Fluid Simulation\n\n";

    cout << "Enter \"help\" to see the options" << endl;

    string userInput = {};
    while(true){
        cout << "\nEnter a prompt :";
        getline(cin,userInput);

        if(userInput.compare("exit") == 0){
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
                    "   sim an object starting under the water\n";
            continue;
        }
        else if(userInput.compare("test1") == 0){
            cout << "Don't have the sim ready yet" << endl;
            //simulate test1
            continue;
        }
        else if(userInput.compare("test2") == 0){
            cout << "Don't have the sim ready yet" << endl;
            //simulate test2

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
    



    return 0;
}


int runTest2(){
    
    //Not implemented yet

    return 0;
}
