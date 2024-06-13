#pragma once

#include <array>
#include <vector>
#include <utility>

// use constexpr inside a namespace, instead of enum or enum-class, so can we work with ints directly AND have type-safety
namespace ID     { constexpr int WATER = -1; constexpr int LAND  = -2; }
namespace IMAGE  { constexpr int HEIGHT = 50; constexpr int WIDTH  = 80; }
namespace SYMBOL { constexpr char WATER = '.'; }

namespace land {

    using Map   = std::array<std::array<int, IMAGE::WIDTH>, IMAGE::HEIGHT>; // contains water and non-water/island numbers
    using Stack = std::vector<std::pair<int, int>>; // stores coordinates of pixels whose neighbors we still need to check

} // namespace land
