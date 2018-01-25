//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Hardware interference unittests.
 */

#include <pycpp/stl/new/hardware_interference.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct naive_aligned_int
{
    int value;
};

struct cache_aligned_int
{
    alignas(hardware_destructive_interference_size) int value;
};

struct bad_pair
{
    int first;
    char padding[hardware_constructive_interference_size];
    int second;
};

struct good_pair
{
    int first;
    int second;
};

// TESTS
// -----

TEST(new_module, hardware_interference)
{
    static_assert(alignof(naive_aligned_int) < hardware_destructive_interference_size, "");
    static_assert(alignof(cache_aligned_int) == hardware_destructive_interference_size, "");
    static_assert(sizeof(bad_pair) > hardware_constructive_interference_size, "");
    static_assert(sizeof(good_pair) <= hardware_constructive_interference_size, "");
}
