/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#include <gtest/gtest.h>
#include <itl/stack.hpp>

// TESTS
// -----


TEST(stack, MemberFunctions)
{
    itl::stack<int> x(std::deque<int> {5, 4, 3, 2});
    itl::stack<int> y;
    x.swap(y);

    EXPECT_EQ(x.size(), 0);
    EXPECT_EQ(y.size(), 4);
}


TEST(stack, NonMemberFunctions)
{
    itl::stack<int> x(std::deque<int> {1});
    itl::stack<int> y(std::deque<int> {2});

    EXPECT_TRUE(x < y);
    EXPECT_TRUE(x <= y);
    EXPECT_TRUE(x != y);
    EXPECT_TRUE(y > x);
    EXPECT_TRUE(y >= x);
    EXPECT_TRUE(x == x);

    std::swap(x, y);
    EXPECT_EQ(x.top(), 2);
    EXPECT_EQ(y.top(), 1);
}
