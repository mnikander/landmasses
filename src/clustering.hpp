#pragma once

#include <array>
#include <vector>
#include <utility>

#include "common.hpp"

namespace land {

    namespace { // anonymous namespace for details

        inline bool is_in_bounds(int row, int col) { return (0 <= row) && (row < IMAGE::HEIGHT) && (0 <= col) && (col < IMAGE::WIDTH);}
        inline bool is_unmarked(int row, int col, Map const& map) { return map[row][col] == ID::LAND; };
        inline void mark(int row, int col, Map & map, int islandNumber) { map[row][col] = islandNumber; };
        inline void push(int row, int col, Stack & placesToSearch) { placesToSearch.push_back({row, col}); }
        inline std::pair<int, int> pop(Stack & placesToSearch) { const std::pair<int, int> result = placesToSearch.back(); placesToSearch.pop_back(); return result; }

    } // namespace anonymous

    //! iterate over every pixel and start a depth-first search to find all of its connected components
    inline int cluster_landmasses(Map & map)
    {
        int islandNumber = 0;
        Stack placesToSearch{}; // use a stack for DFS, instead of recursion, to avoid the recursion-depth limit

        for(int h = 0; h < IMAGE::HEIGHT; ++h)
        {
            for(int w = 0; w < IMAGE::WIDTH; ++w)
            {
                if(is_unmarked(h, w, map))
                {
                    ++islandNumber;
                    mark(h, w, map, islandNumber);
                    push(h, w, placesToSearch);

                    while(placesToSearch.size() > 0)
                    {
                        const auto& [r, c] = pop(placesToSearch);

                        // 3x3 kernel
                        for(int row = r-1; row <= r+1; ++row)
                        {
                            for(int col = c-1; col <= c+1; ++col)
                            {
                                if(is_in_bounds(row, col) && is_unmarked(row, col, map))
                                {
                                    mark(row, col, map, islandNumber);
                                    push(row, col, placesToSearch);
                                }
                            }
                        }
                    }
                }
            }
        }
        return islandNumber;
    }

} // namespace land
