//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing multiplies unittests.
 */

#include <pycpp/stl/functional/multiplies.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, multiplies)
{
    int x = 1;
    int y = 2;
    int z = 3;
    multiplies<> op;
    EXPECT_EQ(op(x, y), 2);
    EXPECT_EQ(op(x, z), 3);
    EXPECT_EQ(op(y, z), 6);
}
