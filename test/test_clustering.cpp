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

TEST(clustering, up)
{
    const land::Image<char, 3, 3, 1> chart(land::up, '.');
    const land::Image<int, 3, 3, 1> clusters = land::clustering(chart);

    EXPECT_EQ(clusters.size(), 9);
    EXPECT_EQ(clusters.padded_size(), 25);
    EXPECT_EQ(number_of_clusters(clusters), 1);

    // check the padding
    EXPECT_EQ(clusters(-1, -1), ID::WATER);
    EXPECT_EQ(clusters(-1, 0), ID::WATER);
    EXPECT_EQ(clusters(-1, 1), ID::WATER);
    EXPECT_EQ(clusters(-1, 2), ID::WATER);
    EXPECT_EQ(clusters(-1, 3), ID::WATER);
    EXPECT_EQ(clusters(0, -1), ID::WATER);
    EXPECT_EQ(clusters(0, 3), ID::WATER);
    EXPECT_EQ(clusters(1, -1), ID::WATER);
    EXPECT_EQ(clusters(1, 3), ID::WATER);
    EXPECT_EQ(clusters(2, -1), ID::WATER);
    EXPECT_EQ(clusters(2, 3), ID::WATER);
    EXPECT_EQ(clusters(3, -1), ID::WATER);
    EXPECT_EQ(clusters(3, 0), ID::WATER);
    EXPECT_EQ(clusters(3, 1), ID::WATER);
    EXPECT_EQ(clusters(3, 2), ID::WATER);
    EXPECT_EQ(clusters(3, 3), ID::WATER);

    // actual pixels
    EXPECT_EQ(clusters(0, 0), ID::WATER);
    EXPECT_EQ(clusters(0, 1), 1);
    EXPECT_EQ(clusters(0, 2), ID::WATER);
    EXPECT_EQ(clusters(1, 0), 1);
    EXPECT_EQ(clusters(1, 1), ID::WATER);
    EXPECT_EQ(clusters(1, 2), 1);
    EXPECT_EQ(clusters(2, 0), 1);
    EXPECT_EQ(clusters(2, 1), ID::WATER);
    EXPECT_EQ(clusters(2, 2), 1);
}

TEST(clustering, down)
{
    const land::Image<char, 3, 3, 1> chart(land::down, '.');
    const land::Image<int, 3, 3, 1> clusters = land::clustering(chart);
    EXPECT_EQ(number_of_clusters(clusters), 1);

    EXPECT_EQ(clusters.size(), 9);
    EXPECT_EQ(clusters.padded_size(), 25);

    // actual pixels
    EXPECT_EQ(clusters(0, 0), 1);
    EXPECT_EQ(clusters(0, 1), ID::WATER);
    EXPECT_EQ(clusters(0, 2), 1);
    EXPECT_EQ(clusters(1, 0), 1);
    EXPECT_EQ(clusters(1, 1), ID::WATER);
    EXPECT_EQ(clusters(1, 2), 1);
    EXPECT_EQ(clusters(2, 0), ID::WATER);
    EXPECT_EQ(clusters(2, 1), 1);
    EXPECT_EQ(clusters(2, 2), ID::WATER);
}

TEST(clustering, left)
{
    const land::Image<char, 3, 3, 1> chart(land::left, '.');
    const land::Image<int, 3, 3, 1> clusters = land::clustering(chart);

    EXPECT_EQ(clusters.size(), 9);
    EXPECT_EQ(clusters.padded_size(), 25);
    EXPECT_EQ(number_of_clusters(clusters), 1);

    // actual pixels
    EXPECT_EQ(clusters(0, 0), ID::WATER);
    EXPECT_EQ(clusters(0, 1), 1);
    EXPECT_EQ(clusters(0, 2), 1);
    EXPECT_EQ(clusters(1, 0), 1);
    EXPECT_EQ(clusters(1, 1), ID::WATER);
    EXPECT_EQ(clusters(1, 2), ID::WATER);
    EXPECT_EQ(clusters(2, 0), ID::WATER);
    EXPECT_EQ(clusters(2, 1), 1);
    EXPECT_EQ(clusters(2, 2), 1);
}

TEST(clustering, right)
{
    const land::Image<char, 3, 3, 1> chart(land::right, '.');
    const land::Image<int, 3, 3, 1> clusters = land::clustering(chart);

    EXPECT_EQ(clusters.size(), 9);
    EXPECT_EQ(clusters.padded_size(), 25);
    EXPECT_EQ(number_of_clusters(clusters), 1);

    // actual pixels
    EXPECT_EQ(clusters(0, 0), 1);
    EXPECT_EQ(clusters(0, 1), 1);
    EXPECT_EQ(clusters(0, 2), ID::WATER);
    EXPECT_EQ(clusters(1, 0), ID::WATER);
    EXPECT_EQ(clusters(1, 1), ID::WATER);
    EXPECT_EQ(clusters(1, 2), 1);
    EXPECT_EQ(clusters(2, 0), 1);
    EXPECT_EQ(clusters(2, 1), 1);
    EXPECT_EQ(clusters(2, 2), ID::WATER);
}


TEST(clustering, corners)
{
    const land::Image<char, 3, 3, 1> chart(land::corners, '.');
    const land::Image<int, 3, 3, 1> clusters = land::clustering(chart);

    EXPECT_EQ(clusters.size(), 9);
    EXPECT_EQ(clusters.padded_size(), 25);
    EXPECT_EQ(number_of_clusters(clusters), 4);

    // actual pixels
    EXPECT_EQ(clusters(0, 0), 1);
    EXPECT_EQ(clusters(0, 1), ID::WATER);
    EXPECT_EQ(clusters(0, 2), 2);
    EXPECT_EQ(clusters(1, 0), ID::WATER);
    EXPECT_EQ(clusters(1, 1), ID::WATER);
    EXPECT_EQ(clusters(1, 2), ID::WATER);
    EXPECT_EQ(clusters(2, 0), 3);
    EXPECT_EQ(clusters(2, 1), ID::WATER);
    EXPECT_EQ(clusters(2, 2), 4);
}

}
