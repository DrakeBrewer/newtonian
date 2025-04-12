#include "fluidSim.hpp"
#include "rigidBody.hpp"

// --------Tests---------

// Has user input for the object and the fluid
int run(){
    cout << "Select which object and fluid." << endl;

    string userInput = {};
    //Getting users input for what object to use
    while(true){    
        cout << "\nSelect object:";
        getline(cin,userInput);
        if(userInput == "exit" || userInput == "q"){
            cout << "Exiting...\n";
            return 1;
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
            break;
        }
    }
    //Need: to implement rigidBody objects

    //object obj(userInput);

    //Getting users input for what fluid to use
    while(true){
        cout << "\nSelect fluid:";
        getline(cin,userInput);
        if(userInput == "exit" || userInput == "q"){
            cout << "Exiting...\n";
            return 1;
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
            break;
        }
    }
    //Need: to implement rigidBody objects

    //fluid liquid(userInput);

    //Set height of the object
    while(true){
        cout << "\nSet Object Height (-20 to 20):";
        getline(cin,userInput);
        if(userInput == "exit" || userInput == "q"){
            cout << "Exiting...\n";
            return 1;
        }
        else if(userInput == "help"){
            cout << "help: list commands\nexit: to quit\n";
            continue;
        }
        float num = stof(userInput);
        if(num >= -20 && num <= 20){
            obj.setZ(num);
            break;
        }
        cout << "Invalid number for height of the object" << endl;
    }
    
    //run Sim
    int simResult = runSimulation(obj, liquid, true);

    if(simResult) cout << "\nObject: " << obj.name << ", Sinks" << endl;
    else cout << "\nObject: " << obj.name << ", Floats" << endl;

    return 0;
}



int runTest1(){
    //The top of the water level is at z=0 , everything less than 0 is water

    string input;
    //Need: to implement rigidBody objects

    //object obj("rock",10);
    //fluid liquid("water", 0);
    float sec = 0; float reachedIn = 0;
    int reachedFlag = 0;
    float velocity = obj.getInitV();//inital velocity
    float dt = 0.01; // Time step in seconds
    while((std::abs(velocity) > 0.01 || std::abs(obj.getZ()) > .01) && obj.getZ() > -20){
        float force = netForce(obj,liquid,velocity);
        float acceleration = force / obj.getMass();
        velocity += acceleration * dt;
        obj.setZ(obj.getZ() - velocity * dt);

        std::cout << "\rz: " << fflush(stdout) << obj.getZ() << " m" << ", velocity: " << velocity << " m/s" << 
            "Time: " << sec;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));; //Slows down the simulation
        sec += dt;
        if(!reachedFlag) reachedIn = sec;
        if(!reachedFlag && (obj.z < 0)) reachedFlag++;
    }


    cout<<"\nSimulation Done\n";
    cout<<"Finished in "<< sec << " seconds." << endl;
    cout<<"Object reached the liquid in "<< reachedIn << " seconds." << endl;
    cout<<"liquid  density is "<< liquid.getDensity() << endl;
    cout<<"object  mass is "<< obj.getMass() << endl;

    return 0;
}

int runTest2(){
    
    string input;
    int sec = 0;
    int vFin = 0;

    //Need: to implement rigidBody objects

    //object obj("wood",-10);
    //fluid liquid("water");

    int simResult = runSimulation(obj, liquid, true);

    cout<<"Simulation Done\n";

    return 0;
}


//----------Functions----------

float netForce(object obj, fluid liquid, float velocity){
    float dragCoefficient = obj.dragCoe;
    float g = 9.80665;
    float buoyantForce = liquid.getDensity() * obj.getVolume() * g;
    float weight = obj.getMass() * g;
    float drag;
    float airDensity = 1.225;

    if(obj.getZ() >= 0 ){
        drag = .5 * dragCoefficient * airDensity * obj.area() * velocity * std::abs(velocity);
        return weight - drag;
    }
    drag = .5 * dragCoefficient * liquid.getDensity() * obj.area() * velocity * std::abs(velocity);
    return weight - buoyantForce - drag;
}

int runSimulation(object obj, fluid liquid, bool printFlag){
    float velocity = obj.getInitV();//inital velocity
    float dt = 0.01; // Time step in seconds
    while((std::abs(velocity) > 0.03 || std::abs(obj.getZ()) > .03) && obj.getZ() >= -20){
        float force = netForce(obj,liquid,velocity);
        float acceleration = force / obj.getMass();
        velocity += acceleration * dt;
        obj.setZ(obj.getZ() - velocity * dt);

        if(printFlag){
            std::cout << "\rz: " << obj.getZ() << " m" << ", velocity: " << velocity << " m/s";
            std::this_thread::sleep_for(std::chrono::milliseconds(10));; //Slows down the simulation
        }
    }

    if(obj.getZ() <= -20) return 1; // Object sinks
    else return 0;                  // Object floats
}

void userInterface(){
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
                    "   A rock starts at a height of 10 meters and with a velocity of 0\n"
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
            cout << "Running Test1" << endl;
            runTest1();
            continue;
        }
        else if(userInput.compare("test2") == 0){
            cout << "Running Test2" << endl;
            runTest2();
            continue;
        }
        else{
            cout << "Not a prompt, do \"help\" for prompts" << endl;
            continue;
        }

        break;
    }

    return;
}
