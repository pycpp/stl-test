//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `relocate` extension unittests.
 */

#include <pycpp/stl/memory/relocate.h>
#include <gtest/gtest.h>
#include <type_traits>

PYCPP_USING_NAMESPACE

// TESTS
// -----


TEST(memory, relocate)
{
    using storage_type = typename std::aligned_storage<sizeof(int), alignof(int)>::type;
    constexpr size_t size = 5;
    int x[size] = {0, 1, 2, 3, 4};
    storage_type u[size];

    relocate(x, x+size, reinterpret_cast<int*>(u));
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(reinterpret_cast<int&>(u[i]), i);
    }
}


TEST(memory, relocate_n)
{
    using storage_type = typename std::aligned_storage<sizeof(int), alignof(int)>::type;
    constexpr size_t size = 5;
    int x[size] = {0, 1, 2, 3, 4};
    storage_type u[size];

    relocate_n(x, size, reinterpret_cast<int*>(u));
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(reinterpret_cast<int&>(u[i]), i);
    }
}
