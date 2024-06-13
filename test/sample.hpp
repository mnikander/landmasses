#pragma once

#include <array>

namespace land {

constexpr std::array<char, 5U> symbols        {'.', '+', '*', '@', '^'};
constexpr std::array<char, 6U> invalid_symbols{'.', '+', '*', '@', '^', '#'};

// arrow or U-shapes are tricky for some pixel-kernel based clustering algorithms
constexpr std::array<char, 9> up   {'.', '+', '.',
                                    '+', '.', '+',
                                    '+', '.', '+'};

constexpr std::array<char, 9> down {'+', '.', '+',
                                    '+', '.', '+',
                                    '.', '+', '.'};

constexpr std::array<char, 9> left {'.', '+', '+',
                                    '+', '.', '.',
                                    '.', '+', '+'};

constexpr std::array<char, 9> right{'+', '+', '.',
                                    '.', '.', '+',
                                    '+', '+', '.'};

constexpr std::array<char, 9> corners{'+', '.', '+',
                                      '.', '.', '.',
                                      '+', '.', '+'};

}
