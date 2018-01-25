//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing logical_or unittests.
 */

#include <pycpp/stl/functional/logical_or.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, logical_or)
{
    bool x = false;
    bool y = false;
    bool z = true;
    logical_or<> pred;
    EXPECT_FALSE(pred(x, y));
    EXPECT_TRUE(pred(x, z));
    EXPECT_TRUE(pred(y, z));
}
