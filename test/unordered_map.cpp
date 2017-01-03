/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#include <gtest/gtest.h>
#include <itl/unordered_map.hpp>


TEST(unordered_map, MemberFunctions)
{
    itl::unordered_map<int, int> x = {{5, 4}, {3, 2}};
    itl::unordered_map<int, int> y;
    x.swap(y);

    EXPECT_EQ(x.size(), 0);
    EXPECT_EQ(y.size(), 2);
}


TEST(unordered_map, NonMemberFunctions)
{
    itl::unordered_map<int, int> x = {{0, 1}};
    itl::unordered_map<int, int> y = {{2, 3}};

    EXPECT_TRUE(x != y);
    EXPECT_TRUE(x == x);

    std::swap(x, y);
    EXPECT_EQ(x[2], 3);
    EXPECT_EQ(y[0], 1);
}


TEST(unordered_multimap, MemberFunctions)
{
    itl::unordered_multimap<int, int> x = {{5, 4}, {3, 2}};
    itl::unordered_multimap<int, int> y;
    x.swap(y);

    EXPECT_EQ(x.size(), 0);
    EXPECT_EQ(y.size(), 2);
}


TEST(unordered_multimap, NonMemberFunctions)
{
    itl::unordered_multimap<int, int> x = {{0, 1}};
    itl::unordered_multimap<int, int> y = {{2, 3}};

    EXPECT_TRUE(x != y);
    EXPECT_TRUE(x == x);

    std::swap(x, y);
    EXPECT_EQ(x.find(2)->second, 3);
    EXPECT_EQ(y.find(0)->second, 1);
}
