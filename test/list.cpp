/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#include <gtest/gtest.h>
#include <itl/list.hpp>

// TESTS
// -----


TEST(list, MemberFunctions)
{
    itl::list<int> x = {5, 4, 3, 2};
    itl::list<int> y;
    x.swap(y);

    EXPECT_EQ(x.size(), 0);
    EXPECT_EQ(y.size(), 4);
}


TEST(list, NonMemberFunctions)
{
    itl::list<int> x = {1};
    itl::list<int> y = {2};

    EXPECT_TRUE(x < y);
    EXPECT_TRUE(x <= y);
    EXPECT_TRUE(x != y);
    EXPECT_TRUE(y > x);
    EXPECT_TRUE(y >= x);
    EXPECT_TRUE(x == x);

    std::swap(x, y);
    EXPECT_EQ(x.front(), 2);
    EXPECT_EQ(y.front(), 1);

    x.merge(y);
    EXPECT_EQ(x.size(), 2);
    EXPECT_EQ(y.size(), 0);

    y.splice(y.begin(), x);
    EXPECT_EQ(y.size(), 2);
    EXPECT_EQ(x.size(), 0);
}
