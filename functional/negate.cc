//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing negate unittests.
 */

#include <pycpp/stl/functional/negate.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, negate)
{
    int x = 1;
    int y = -2;
    int z = 3;
    negate<> op;
    EXPECT_EQ(op(x), -1);
    EXPECT_EQ(op(y), 2);
    EXPECT_EQ(op(z), -3);
}
