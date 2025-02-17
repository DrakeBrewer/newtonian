#include <iostream>
#include <math.h>

int main (){

    std::cout << "Welcome, you have entered the light simulator" << std::endl;

    std::cout << "Enter \"help\" to see the options" << std::endl;
    
    std::string userInput = {};
    while(true){

	std::cout << "\nlightSim >";
	getline(std::cin,userInput);

	if(userInput.compare("exit") == 0 || userInput == "q"){
	    std::cout << "Goodbye...\n";
	    break;
	}
	else if(userInput == "help"){
	    std::cout << "Options\n"
		"exit: exit the program\n"
		"refraction: simulate refraction of light\n"
		"reflection: simulate reflection of light\n"
		"details: detailed explanation of each test\n"<< std::endl;
	    continue;
	}
	else if(userInput == "details"){
	    std::cout << "Detailing...\n"
		"refraction: Simulate light traveling between two mediums. A ray will bend at an angle governed by Snell's law. Example: Lenses bending light.\n"
		"reflection: Simulate light bouncing off the surface of a mirror.\n"
		<< std::endl;
	}
	else if(userInput.compare("reflection") == 0){
	    std::cout << "Starting reflection sim" << std::endl;
	    continue;
	}
	else if(userInput.compare("refraction") == 0){
	    std::cout << "Starting refraction sim" << std::endl;
	}
	else {
	    std::cout << "Not a prompt, try \"help\"." << std::endl;
	}

	break;
    }

    return 0;
}
