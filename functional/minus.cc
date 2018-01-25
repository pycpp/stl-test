//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing minus unittests.
 */

#include <pycpp/stl/functional/minus.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, minus)
{
    int x = 1;
    int y = 2;
    int z = 3;
    minus<> op;
    EXPECT_EQ(op(x, y), -1);
    EXPECT_EQ(op(x, z), -2);
    EXPECT_EQ(op(y, z), -1);
}
