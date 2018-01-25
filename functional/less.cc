//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing less unittests.
 */

#include <pycpp/stl/functional/less.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, less)
{
    int x = 1;
    int y = 2;
    int z = 2;
    less<> pred;
    EXPECT_TRUE(pred(x, y));
    EXPECT_TRUE(pred(x, z));
    EXPECT_FALSE(pred(y, z));
    EXPECT_FALSE(pred(z, x));
}
