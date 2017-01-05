/*
 *  :author: The Regents of the University of California.
 *  :license: Public Domain
 *
 *  This file has been placed in the public domain.
 *  There are no restrictions on its use.
 */

#include <gtest/gtest.h>
#include <itl/unordered_map.hpp>
#include <itl/memory.hpp>
#include <sstream>


TEST(shared_ptr, MemberFunctions)
{
    itl::shared_ptr<int> x(new int(5));
    itl::shared_ptr<int> y(new int(3));
    x.swap(y);

    EXPECT_EQ(*x, 3);
    EXPECT_EQ(*y, 5);
}


TEST(shared_ptr, NonMemberFunctions)
{
    itl::shared_ptr<int> x(new int(5));
    itl::shared_ptr<int> y(new int(3));
    auto z = itl::make_shared<int>(5);
    std::allocator<int> alloc;
    auto w = itl::allocate_shared<int>(alloc, 5);

    // don't care about value, random pointer locations
    // just care methods successfully call
    EXPECT_TRUE(x < y | true);
    EXPECT_TRUE(x <= y | true);
    EXPECT_TRUE(x == y | true);
    EXPECT_TRUE(x != y | true);
    EXPECT_TRUE(x >= y | true);
    EXPECT_TRUE(x > y | true);

    itl::swap(x, y);
    EXPECT_EQ(*x, 3);
    EXPECT_EQ(*y, 5);

    EXPECT_FALSE(itl::get_deleter<void(*)(int*)>(x));

    std::ostringstream stream;
    stream << x;
    std::map<std::shared_ptr<int>, int> map;

    // check atomic friends
    itl::shared_ptr<int> a, b, c;
    EXPECT_TRUE(itl::atomic_is_lock_free(&x) | true);
    itl::atomic_store(&x, a);
    itl::atomic_store_explicit(&x, a, std::memory_order_seq_cst);
    EXPECT_TRUE(itl::atomic_compare_exchange_weak(&x, &a, b) | true);
    EXPECT_TRUE(itl::atomic_compare_exchange_strong(&x, &a, b) | true);
    EXPECT_TRUE(itl::atomic_compare_exchange_strong_explicit(&x, &a, b, std::memory_order_seq_cst, std::memory_order_seq_cst) | true);
    EXPECT_TRUE(itl::atomic_compare_exchange_weak_explicit(&x, &a, b, std::memory_order_seq_cst, std::memory_order_seq_cst) | true);
}


TEST(shared_ptr, Casts)
{
    itl::shared_ptr<int> x(new int(5));
    auto i = itl::static_pointer_cast<int>(x);
    auto c = itl::const_pointer_cast<const int>(i);
    auto u = itl::reinterpret_pointer_cast<const unsigned int>(i);
}


TEST(weak_ptr, MemberFunctions)
{
    itl::shared_ptr<int> x(new int(5));
    itl::weak_ptr<int> w1(x);
    itl::weak_ptr<int> w2(x);
    itl::swap(w1, w2);
    w1.swap(w2);

    itl::shared_ptr<int> z(w1);
}
