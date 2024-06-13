#include <array>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <utility>
#include <string>
#include <vector>

// use constexpr inside a namespace, instead of enum or enum-class, so can we work with ints directly AND have type-safety
namespace ID     { constexpr int WATER = -1; constexpr int LAND  = -2; }
namespace IMAGE  { constexpr int HEIGHT = 50; constexpr int WIDTH  = 80; }
namespace SYMBOL { constexpr char WATER = '.'; }

namespace land {

    using Map   = std::array<std::array<int, IMAGE::WIDTH>, IMAGE::HEIGHT>; // contains water and non-water/island numbers
    using Stack = std::vector<std::pair<int, int>>; // stores coordinates of pixels whose neighbors we still need to check

    namespace { // anonymous namespace for details

        bool is_in_bounds(int row, int col) { return (0 <= row) && (row < IMAGE::HEIGHT) && (0 <= col) && (col < IMAGE::WIDTH);}
        bool is_unmarked(int row, int col, Map const& map) { return map[row][col] == ID::LAND; };
        void mark(int row, int col, Map & map, int islandNumber) { map[row][col] = islandNumber; };
        void push(int row, int col, Stack & placesToSearch) { placesToSearch.push_back({row, col}); }
        std::pair<int, int> pop(Stack & placesToSearch) { const std::pair<int, int> result = placesToSearch.back(); placesToSearch.pop_back(); return result; }

    } // namespace anonymous

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

    //! iterate over every pixel and start a depth-first search to find all of its connected components
    int cluster_landmasses(Map & map)
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

    std::cout << "Nikander: there are " << count << " landmasses in this map." << std::endl;
    return EXIT_SUCCESS;
}
