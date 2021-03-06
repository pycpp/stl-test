//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing equal_to unittests.
 */

#include <pycpp/stl/functional/equal_to.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, equal_to)
{
    int x = 1;
    int y = 2;
    int z = 2;
    equal_to<> pred;
    EXPECT_FALSE(pred(x, y));
    EXPECT_FALSE(pred(x, z));
    EXPECT_TRUE(pred(y, z));
}
