/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#include <gtest/gtest.h>
#include <itl/forward_list.hpp>

// TESTS
// -----


TEST(forward_list, MemberFunctions)
{
    itl::forward_list<int> x = {5, 4, 3, 2};
    itl::forward_list<int> y;
    x.swap(y);

    EXPECT_FALSE(y.empty());
    EXPECT_TRUE(x.empty());
}


TEST(forward_list, NonMemberFunctions)
{
    itl::forward_list<int> x = {1};
    itl::forward_list<int> y = {2};

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
    EXPECT_FALSE(x.empty());
    EXPECT_TRUE(y.empty());

    y.splice_after(y.before_begin(), x);
    EXPECT_FALSE(y.empty());
    EXPECT_TRUE(x.empty());
}
