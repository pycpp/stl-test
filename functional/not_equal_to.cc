//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing not_equal_to unittests.
 */

#include <pycpp/stl/functional/not_equal_to.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, not_equal_to)
{
    int x = 1;
    int y = 2;
    int z = 2;
    not_equal_to<> pred;
    EXPECT_TRUE(pred(x, y));
    EXPECT_TRUE(pred(x, z));
    EXPECT_FALSE(pred(y, z));
}
