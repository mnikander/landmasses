#include <cstdlib> // EXIT_SUCCESS
#include <fstream>
#include <iostream>
#include <string>

#include "constants.hpp"
#include "image.hpp"
#include "io.hpp"

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        std::cerr << "No filepath provided." << std::endl;
        return EXIT_FAILURE;
    }
    std::string filepath(argv[1]);
    std::ifstream file(filepath);

    if(!file)
    {
        std::cerr << "Unable to open file." << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Reading: " << filepath << std::endl;

    const auto image = land::read_map<MAP::HEIGHT, MAP::WIDTH>(file);
    land::print(image);

    return EXIT_SUCCESS;
}
