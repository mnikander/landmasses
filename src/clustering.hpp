#pragma once

#include <algorithm>
#include "constants.hpp"
#include "image.hpp"

namespace land {

template<int Height, int Width, int Padding>
Image<int, Height, Width, Padding> chart_to_int_image(Image<char, Height, Width, Padding> const& chart)
{
    Image<int, Height, Width, Padding> image{};
    std::transform(chart._data.cbegin(), chart._data.cend(), image._data.begin(), 
                   [](char c){ return c == SYMBOL::WATER ? ID::WATER : ID::UNASSIGNED; });
    return image;
}

// connected components: iterate over every pixel and start depth-first search using a 3x3 kernel to identify neighbors
template<int Height, int Width, int Padding>
Image<int, Height, Width, Padding> clustering(Image<char, Height, Width, Padding> const& chart)
{
    Image<int, Height, Width, Padding> image = chart_to_int_image(chart);
    int clusterId                            = ID::FIRST_CLUSTER;

    std::vector<Coordinate> stack{};

    for(int h = 0; h < Height; ++h)
    {
        for(int w = 0; w < Width; ++w)
        {
            if(image(h, w) == ID::UNASSIGNED)
            {
                const Coordinate c{h, w};
                stack.push_back(c);
                image(c) = ID::QUEUED;

                while(stack.size() != 0U)
                {
                    const Coordinate current = stack.back();
                    image(current)           = clusterId;
                    stack.pop_back();

                    for(int r = -1; r <= 1; ++r)
                    {
                        for(int c = -1; c <= 1; ++c)
                        {
                            Coordinate other{current.row+r, current.col+c};

                            if(image(other) == ID::UNASSIGNED)
                            {
                                stack.push_back(other);
                                image(other) = ID::QUEUED;
                            }
                        }
                    }
                }
                ++clusterId;
            }
        }
    }
    return image;
}

template<int Height, int Width, int Padding>
int count_clusters(Image<int, Height, Width, Padding> const& clusters)
{
    const auto iter  = std::max_element(clusters._data.cbegin(), clusters._data.cend());
    const int number = *iter;
    return std::max(0, number); // if it's negative, make it zero
}

}
