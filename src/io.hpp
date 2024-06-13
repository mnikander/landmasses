#pragma once

#include <fstream>
#include <string>

#include "common.hpp"

namespace land {

    //! load a map from an ifstream and set IDs corresponding to water and non-water pixels
    Map create_map(std::ifstream& file)
    {
        Map map{};

        for (int h = 0; h < IMAGE::HEIGHT; ++h)
        {
            std::string line{};
            if(std::getline(file, line))
            {
                for (int w = 0; w < IMAGE::WIDTH; ++w)
                {
                    map[h][w] = (line[w] == SYMBOL::WATER) ? ID::WATER : ID::LAND;
                }
            }
        }
        return map; // copying is avoided due to return-value optimization
    }

} // namespace land
