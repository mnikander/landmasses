#include <algorithm>
#include <cstdlib>
#include <iostream>

#include "image.hpp"

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        std::cerr << "No filepath provided." << std::endl;
        return EXIT_FAILURE;
    }
    std::string filepath(argv[1]);
    std::cout << filepath << std::endl;

    return EXIT_SUCCESS;
}
