#pragma once

#include <array>

namespace land {

template <typename T, int Height, int Width>
struct Image
{
    static constexpr int index(int row, int col)     { return row*Width + col; } // row-major
    
    T& operator()(int row, int col)              { return _data[index(row, col)]; }
    const T& operator()(int row, int col) const { return _data[index(row, col)]; }

    std::array<char, Height*Width> _data;
};

}
