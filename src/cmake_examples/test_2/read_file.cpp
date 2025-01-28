#include <iostream>
#include <string>
#include <fstream>

// Read the file given by argv[1] and print the contents line by line
int main(int argc, char * argv[])
{
    if(argc < 2) // needs file name
    {
        std::cout << "Error: No filename given" << std::endl;
        return 1;
    }
    
    std::ifstream file; // create a ifstream object
    file.open(argv[1]); // open the file
    if(!file) // check if open failed
    {
        std::cerr << "Unable to open file <" << argv[1] << ">" << std::endl;
        exit(0);
    }
    std::string line; // create a string
    if(file.is_open())
    {
        while (std::getline(file,line)) // read line by line
        {
            std::cout << line << std::endl; // print the contents of that line
        }
        file.close(); // close file
    }
    return 0;
}
