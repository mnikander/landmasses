#pragma once

#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <iostream>
#include <string>

#include "image.hpp"

namespace map {
    constexpr int HEIGHT = 50;
    constexpr int WIDTH  = 80;
}

namespace land {

template<int Height, int Width>
land::Image<char, Height, Width> read_map(std::ifstream& file)
{
    land::Image<char, Height, Width> image{};
    for (int row = 0; row < Height; ++row)
    {
        std::string line{};
        if(std::getline(file, line))
        {
            std::copy(line.cbegin(), line.cend(), image._data.begin()+(row*image.width()));
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
