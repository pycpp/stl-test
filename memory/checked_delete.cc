//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Checked deletion for complete type unittests.
 */

#include <pycpp/stl/memory/checked_delete.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(checked_delete, complete)
{
    int* a = new int(5);
    checked_delete(a);
}


TEST(checked_array_delete, complete)
{
    int* a = new int[5];
    checked_array_delete(a);
}


TEST(checked_deleter, complete)
{
    int* a = new int(5);
    using deleter = checked_deleter<int>;
    deleter()(a);
}


TEST(checked_array_deleter, complete)
{
    int* a = new int[5];
    using deleter = checked_array_deleter<int>;
    deleter()(a);
}
