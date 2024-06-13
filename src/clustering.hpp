#pragma once

#include <algorithm>
#include "constants.hpp"
#include "image.hpp"

namespace land {

template<int Height, int Width, int Padding>
Image<int, Height, Width, Padding> preprocess(Image<char, Height, Width, Padding> const& chart)
{
    Image<int, Height, Width, Padding> image{};
    std::transform(chart._data.cbegin(), chart._data.cend(), image._data.begin(), 
                   [](char c){ return c == SYMBOL::WATER ? ID::WATER : ID::UNASSIGNED; });
    return image;
}

}
