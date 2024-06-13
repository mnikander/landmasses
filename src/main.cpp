#include <cstdlib> // EXIT_SUCCESS
#include <fstream>
#include <iostream>
#include <string>

#include "constants.hpp"
#include "clustering.hpp"
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

    const auto image = land::read_map<MAP::HEIGHT, MAP::WIDTH, MAP::PADDING>(file);
    const land::Image<int, MAP::HEIGHT, MAP::WIDTH, MAP::PADDING> clusters = land::clustering(image);

    std::cout << "There are " << number_of_clusters(clusters) << " landmasses in this map." << std::endl;

    return EXIT_SUCCESS;
}
