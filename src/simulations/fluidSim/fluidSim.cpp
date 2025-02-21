#include "fluid.hpp"
#include "object.hpp"

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
                    "run: runs sim with user's input\n"
                    "test1: sim an object falling into water\n"
                    "test2: sim an object starting under the water\n"
                    "details: detailed explanation of each test" << endl;
            continue;
        }
        else if(userInput == "details"){
            cout << "Detailed Explanation\n"
                    "run:\n"
                    "   Fluid level is at 0 and the user chooses what fluid, object and\n"
                    "   the height of the object are\n"
                    "test1:\n" 
                    "   Object starts at a height of 10 meters and with a velocity of 0\n"
                    "test2:\n"
                    "   Object starts at a height of -10 meters (in the water)\n"
                    "   and a velocity of 0\n";
            continue;
        }
        else if(userInput == "run"){
            cout << "Running Simulation" << endl;
            run();
            cout << "Simulation Finished" << endl;
            continue;
        }
        else if(userInput.compare("test1") == 0){
            cout << "Don't have the sim ready yet" << endl;
            runTest1();
            continue;
        }
        else if(userInput.compare("test2") == 0){
            cout << "Don't have the sim ready yet" << endl;
            runTest2();
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


// Bouyant force thats pushing up is "density(fluid) * volume(object) * gravity"
//
// Density = mass / volume
//
// Volume = mass / density


// --------Tests---------

// need: to add user input for object and fluid
//       - type and initial values
// need: to implement buoyancy force and fluid pressure to simulate the object under
//       a fluid.
// need: to change the format of the test so that it finished in a certain time
//       (this is because if the object sinks it will sink forever in this sim)
//       or set a ground level in the fluid
// need: freefall equations if a object it falling into the fluid
//       (to know the final velocity of the object before it enters the fluid)

int run(){
    cout << "Select which object and fluid." << endl;

    string userInput = {};
    //Getting users input for what object to use
    while(true){    
        cout << "\nSelect object:";
        getline(cin,userInput);
        if(userInput == "exit" || userInput == "q"){
            cout << "Exiting...\n";
            return 0;
        }
        else if(userInput == "help"){
            cout << "list: for list of objects\nhelp: list commands\nexit: to quit";
            continue;
        }
        else if(userInput == "list"){
            cout << "List of Objects\nwood, aluminium, rock\n";
            continue;
        }
        else if(userInput == "wood" ||userInput == "aluminium" ||userInput == "rock"){
            object obj(userInput);
            break;
        }
    }
    //Getting users input for what fluid to use
    while(true){
        cout << "\nSelect fluid:";
        getline(cin,userInput);
        if(userInput == "exit" || userInput == "q"){
            cout << "Exiting...\n";
            return 0;
        }
        else if(userInput == "help"){
            cout << "list: for list of fluids\nhelp: list commands\nexit: to quit";
            continue;
        }
        else if(userInput == "list"){
            cout << "List of Fluids\nwater, oil, corn syrup\n";
            continue;
        }
        else if(userInput == "water" ||userInput == "oil" ||userInput == "corn syrup" ){
            fluid liquid(userInput);
            break;
        }
    }
    //Set height of the object
    while(true){
        cout << "\nSet Object Height (-20 to 20):";
        getline(cin,userInput);
        if(userInput == "exit" || userInput == "q"){
            cout << "Exiting...\n";
            return 0;
        }
        else if(userInput == "help"){
            cout << "help: list commands\nexit: to quit\n";
            continue;
        }
        float num = stof(userInput);
        else if(num > -20 && num < 20){
            //
        }
    }

    

    return 1;
}


int runTest1(){
    //The top of the water level is at z=0 , everything less than 0 is water

    string input;
    int sec = 0;
    int vFin = 0;

    object obj("wood",10);
    //fluid liquid;
    //fluid liquid("water");
    fluid liquid("oil", 5);

    while(obj.getZ() > liquid.getFL()){
        obj.setZ((obj.getZ() - 9.81));
        vFin = obj.getInitV() + (9.81*sec);
        sec++;
        cout<<"Sec:" << sec << "\nObject height:" << obj.getZ()<< endl;
    }

    cout<<"Simulation Done\n";
    cout<<"Object reached the liquid in "<< sec << " seconds." << endl;
    cout<<"liquid  density is "<< liquid.getDensity() << endl;

    return 0;
}

int runTest2(){
    
    string input;
    int sec = 0;
    int vFin = 0;

    object obj("wood",-10);
    fluid liquid("water");

    while(obj.getZ() < liquid.getFL()){

        obj.setZ(obj.getZ() + 1);
        sec++;
        cout<<"Sec:" << sec << "\nObject height:" << obj.getZ()<< endl;
    }

    cout<<"Simulation Done\n";

    return 0;
}
