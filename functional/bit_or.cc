//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing bit_or unittests.
 */

#include <pycpp/stl/functional/bit_or.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, bit_or)
{
    int x = 1;
    int y = 3;
    int z = 4;
    bit_or<> pred;
    EXPECT_EQ(pred(x, y), 3);
    EXPECT_EQ(pred(x, z), 5);
    EXPECT_EQ(pred(y, z), 7);
}
