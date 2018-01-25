//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing less_equal unittests.
 */

#include <pycpp/stl/functional/less_equal.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, less_equal)
{
    int x = 1;
    int y = 2;
    int z = 2;
    less_equal<> pred;
    EXPECT_TRUE(pred(x, y));
    EXPECT_TRUE(pred(x, z));
    EXPECT_TRUE(pred(y, z));
    EXPECT_FALSE(pred(z, x));
}
