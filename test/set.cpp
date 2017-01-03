/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#include <gtest/gtest.h>
#include <itl/set.hpp>


TEST(set, MemberFunctions)
{
    itl::set<int> x = {5, 4, 3, 2};
    itl::set<int> y;
    x.swap(y);

    EXPECT_EQ(x.size(), 0);
    EXPECT_EQ(y.size(), 4);
}


TEST(set, NonMemberFunctions)
{
    itl::set<int> x = {0, 1};
    itl::set<int> y = {2, 3};

    EXPECT_TRUE(x < y);
    EXPECT_TRUE(x <= y);
    EXPECT_TRUE(x != y);
    EXPECT_TRUE(y > x);
    EXPECT_TRUE(y >= x);
    EXPECT_TRUE(x == x);

    std::swap(x, y);
    EXPECT_EQ(*x.find(2), 2);
    EXPECT_EQ(*y.find(0), 0);
}


TEST(multiset, MemberFunctions)
{
    itl::multiset<int> x = {5, 4, 3, 2};
    itl::multiset<int> y;
    x.swap(y);

    EXPECT_EQ(x.size(), 0);
    EXPECT_EQ(y.size(), 4);
}


TEST(multiset, NonMemberFunctions)
{
    itl::multiset<int> x = {0, 1};
    itl::multiset<int> y = {2, 3};

    EXPECT_TRUE(x < y);
    EXPECT_TRUE(x <= y);
    EXPECT_TRUE(x != y);
    EXPECT_TRUE(y > x);
    EXPECT_TRUE(y >= x);
    EXPECT_TRUE(x == x);

    std::swap(x, y);
    EXPECT_EQ(*x.find(2), 2);
    EXPECT_EQ(*y.find(0), 0);
}
