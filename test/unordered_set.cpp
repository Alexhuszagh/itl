/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#include <gtest/gtest.h>
#include <itl/unordered_set.hpp>


TEST(unordered_set, MemberFunctions)
{
    itl::unordered_set<int> x = {5, 4, 3, 2};
    itl::unordered_set<int> y;
    x.swap(y);

    EXPECT_EQ(x.size(), 0);
    EXPECT_EQ(y.size(), 4);
}


TEST(unordered_set, NonMemberFunctions)
{
    itl::unordered_set<int> x = {0, 1};
    itl::unordered_set<int> y = {2, 3};

    EXPECT_TRUE(x != y);
    EXPECT_TRUE(x == x);

    std::swap(x, y);
    EXPECT_EQ(*x.find(2), 2);
    EXPECT_EQ(*y.find(0), 0);
}


TEST(unordered_multiset, MemberFunctions)
{
    itl::unordered_multiset<int> x = {5, 4, 3, 2};
    itl::unordered_multiset<int> y;
    x.swap(y);

    EXPECT_EQ(x.size(), 0);
    EXPECT_EQ(y.size(), 4);
}


TEST(unordered_multiset, NonMemberFunctions)
{
    itl::unordered_multiset<int> x = {0, 1};
    itl::unordered_multiset<int> y = {2, 3};

    EXPECT_TRUE(x != y);
    EXPECT_TRUE(x == x);

    std::swap(x, y);
    EXPECT_EQ(*x.find(2), 2);
    EXPECT_EQ(*y.find(0), 0);
}
