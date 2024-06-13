#include <gtest/gtest.h>
#include "../src/image.hpp"

namespace {

TEST(image, empty)
{
    const land::Image<char, 0, 0> image{};
    ASSERT_EQ(image._data.size(), 0);
}

TEST(image, six)
{
    land::Image<char, 3, 2> image{};
    image._data = {'a', 'b', 'c', 'd', 'e', 'f'};

    ASSERT_EQ(image._data.size(), 6);
    EXPECT_EQ(image(0, 0), 'a');
    EXPECT_EQ(image(0, 1), 'b');
    EXPECT_EQ(image(1, 0), 'c');
    EXPECT_EQ(image(1, 1), 'd');
    EXPECT_EQ(image(2, 0), 'e');
    EXPECT_EQ(image(2, 1), 'f');
}

}
