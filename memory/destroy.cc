//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `destroy*` backport unittests.
 */

#include <pycpp/stl/memory/destroy.h>
#include <gtest/gtest.h>
#include <type_traits>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(memory, destroy_at)
{
    using storage_type = typename std::aligned_storage<sizeof(int), alignof(int)>::type;
    storage_type x;
    new (&x) int(1);
    destroy_at(reinterpret_cast<int*>(&x));
}


TEST(memory, destroy)
{
    using storage_type = typename std::aligned_storage<sizeof(int), alignof(int)>::type;
    size_t size = 5;
    storage_type x[size];
    for (size_t i = 0; i < size; ++i) {
        new (&x[i]) int(i);
    }
    int* first = reinterpret_cast<int*>(x);
    int* last = reinterpret_cast<int*>(x+size);
    destroy(first, last);
}

TEST(memory, destroy_n)
{
    using storage_type = typename std::aligned_storage<sizeof(int), alignof(int)>::type;
    size_t size = 5;
    storage_type x[size];
    for (size_t i = 0; i < size; ++i) {
        new (&x[i]) int(i);
    }
    int* first = reinterpret_cast<int*>(x);
    destroy_n(first, size);
}

