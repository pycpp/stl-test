//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing divides unittests.
 */

#include <pycpp/stl/functional/divides.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, divides)
{
    int x = 1;
    int y = 2;
    int z = 3;
    divides<> op;
    EXPECT_EQ(op(x, y), 0);
    EXPECT_EQ(op(x, z), 0);
    EXPECT_EQ(op(y, z), 0);
}
