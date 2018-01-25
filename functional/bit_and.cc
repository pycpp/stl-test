//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing bit_and unittests.
 */

#include <pycpp/stl/functional/bit_and.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, bit_and)
{
    int x = 1;
    int y = 3;
    int z = 4;
    bit_and<> pred;
    EXPECT_EQ(pred(x, y), 1);
    EXPECT_EQ(pred(x, z), 0);
    EXPECT_EQ(pred(y, z), 0);
}
