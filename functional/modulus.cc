//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing modulus unittests.
 */

#include <pycpp/stl/functional/modulus.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, modulus)
{
    int x = 1;
    int y = 2;
    int z = 3;
    modulus<> op;
    EXPECT_EQ(op(x, y), 1);
    EXPECT_EQ(op(x, z), 1);
    EXPECT_EQ(op(y, z), 2);
}
