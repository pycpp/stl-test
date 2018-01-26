//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `uninitialized_*` backport unittests.
 */

#include <pycpp/stl/memory/uninitialized.h>
#include <gtest/gtest.h>
#include <type_traits>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct xint
{
    int x = 0;
};

// TESTS
// -----

TEST(memory, uninitialized_move)
{
    using storage_type = typename std::aligned_storage<sizeof(int), alignof(int)>::type;
    constexpr size_t size = 5;
    int x[size] = {0, 1, 2, 3, 4};
    storage_type u[size];

    uninitialized_move(x, x+size, reinterpret_cast<int*>(u));
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(reinterpret_cast<int&>(u[i]), i);
    }
}


TEST(memory, uninitialized_move_n)
{
    using storage_type = typename std::aligned_storage<sizeof(int), alignof(int)>::type;
    constexpr size_t size = 5;
    int x[size] = {0, 1, 2, 3, 4};
    storage_type u[size];

    uninitialized_move_n(x, size, reinterpret_cast<int*>(u));
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(reinterpret_cast<int&>(u[i]), i);
    }
}


TEST(memory, uninitialized_default_construct)
{
    using storage_type = typename std::aligned_storage<sizeof(xint), alignof(xint)>::type;
    constexpr size_t size = 5;
    storage_type u[size];

    auto first = reinterpret_cast<xint*>(u);
    auto last = first + size;
    uninitialized_default_construct(first, last);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(reinterpret_cast<xint&>(u[i]).x, 0);
    }
}


TEST(memory, uninitialized_default_construct_n)
{
    using storage_type = typename std::aligned_storage<sizeof(xint), alignof(xint)>::type;
    constexpr size_t size = 5;
    storage_type u[size];

    auto first = reinterpret_cast<xint*>(u);
    uninitialized_default_construct_n(first, size);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(reinterpret_cast<xint&>(u[i]).x, 0);
    }
}


TEST(memory, uninitialized_value_construct)
{
    using storage_type = typename std::aligned_storage<sizeof(xint), alignof(xint)>::type;
    constexpr size_t size = 5;
    storage_type u[size];

    auto first = reinterpret_cast<xint*>(u);
    auto last = first + size;
    uninitialized_value_construct(first, last);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(reinterpret_cast<xint&>(u[i]).x, 0);
    }
}


TEST(memory, uninitialized_value_construct_n)
{
    using storage_type = typename std::aligned_storage<sizeof(xint), alignof(xint)>::type;
    constexpr size_t size = 5;
    storage_type u[size];

    auto first = reinterpret_cast<xint*>(u);
    uninitialized_value_construct_n(first, size);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(reinterpret_cast<xint&>(u[i]).x, 0);
    }
}
