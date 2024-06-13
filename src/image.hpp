#pragma once

#include <array>

namespace land {

struct Coordinate
{
    int row{};
    int col{};
};

template <typename T, int Height, int Width>
struct Image
{
    static constexpr int height()                { return Height; }
    static constexpr int width()                 { return Width; }
    static constexpr int size()                  { return Height * Width; }

    static constexpr int index(int row, int col) { return row*Width + col; } // row-major
    
    T& operator()(int row, int col)              { return _data[index(row, col)]; }
    T& operator()(Coordinate c)                  { return _data[index(c.row, c.col)]; }
    const T& operator()(int row, int col) const  { return _data[index(row, col)]; }
    const T& operator()(Coordinate c) const      { return _data[index(c.row, c.col)]; }

    std::array<char, size()> _data;
};

}
