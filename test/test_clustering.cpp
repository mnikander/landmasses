#include <gtest/gtest.h>
#include "../src/clustering.hpp"
#include "../src/image.hpp"
#include "sample.hpp"

namespace {

TEST(preprocessing, symbols)
{
    const land::Image<char, 1, 5, 0> chart(land::symbols, '.');
    const land::Image<int, 1, 5, 0> result = land::preprocess(chart);

    EXPECT_EQ(result(0, 0), ID::WATER);
    EXPECT_EQ(result(0, 1), ID::UNASSIGNED);
    EXPECT_EQ(result(0, 2), ID::UNASSIGNED);
    EXPECT_EQ(result(0, 3), ID::UNASSIGNED);
    EXPECT_EQ(result(0, 4), ID::UNASSIGNED);
}

}
