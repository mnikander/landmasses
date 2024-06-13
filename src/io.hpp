#pragma once

#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <iostream>
#include <string>

#include "constants.hpp"
#include "image.hpp"

namespace land {

template<int Height, int Width>
land::Image<char, Height, Width> read_map(std::ifstream& file)
{
    land::Image<char, Height, Width> image{};
    std::fill(image._data.begin(), image._data.end(), SYMBOL::WATER); // set everything, especially the padding, to water

    for (int h = 0; h < Height; ++h)
    {
        std::string line{};
        if(std::getline(file, line))
        {
            for (int w = 0; w < Width; ++w)
            {
                image(h, w) = line[w];
            }
        }
    }

    return image;
}

// TODO: it would be much better to just implement this as an ostream operator for the image
template<typename T, int Height, int Width>
void print(land::Image<T, Height, Width> const& image)
{
    for (int h = 0; h < Height; ++h)
    {
        for (int w = 0; w < Width; ++w)
        {
            std::cout << image(h, w) << "";
        }
        std::cout << std::endl;
    }
}

}
