//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing logical_not unittests.
 */

#include <pycpp/stl/functional/logical_not.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, logical_not)
{
    int x = 0;
    int y = 1;
    int z = -1;
    logical_not<> op;
    EXPECT_TRUE(op(x));
    EXPECT_FALSE(op(y));
    EXPECT_FALSE(op(z));
}
