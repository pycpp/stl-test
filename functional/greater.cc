//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing greater unittests.
 */

#include <pycpp/stl/functional/greater.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, greater)
{
    int x = 1;
    int y = 2;
    int z = 2;
    greater<> pred;
    EXPECT_FALSE(pred(x, y));
    EXPECT_FALSE(pred(x, z));
    EXPECT_FALSE(pred(y, z));
    EXPECT_TRUE(pred(z, x));
}
