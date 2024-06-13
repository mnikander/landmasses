#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "clustering.hpp"
#include "common.hpp"
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

    land::Map map   = land::create_map(file);
    const int count = land::cluster_landmasses(map);

    std::cout << "There are " << count << " landmasses in this map." << std::endl;
    return EXIT_SUCCESS;
}
