/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#include <gtest/gtest.h>
#include <itl/vector.hpp>

// TESTS
// -----


TEST(vector, MemberFunctions)
{
    itl::vector<int> x = {5, 4, 3, 2};
    itl::vector<int> y;
    x.swap(y);

    EXPECT_EQ(x.size(), 0);
    EXPECT_EQ(y.size(), 4);
}


TEST(vector, NonMemberFunctions)
{
    itl::vector<int> x = {1};
    itl::vector<int> y = {2};

    EXPECT_TRUE(x < y);
    EXPECT_TRUE(x <= y);
    EXPECT_TRUE(x != y);
    EXPECT_TRUE(y > x);
    EXPECT_TRUE(y >= x);
    EXPECT_TRUE(x == x);

    std::swap(x, y);
    EXPECT_EQ(x[0], 2);
    EXPECT_EQ(y[0], 1);
}
