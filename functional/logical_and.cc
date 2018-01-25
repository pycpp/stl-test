//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing logical_and unittests.
 */

#include <pycpp/stl/functional/logical_and.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, logical_and)
{
    bool x = true;
    bool y = false;
    bool z = true;
    logical_and<> pred;
    EXPECT_FALSE(pred(x, y));
    EXPECT_TRUE(pred(x, z));
    EXPECT_FALSE(pred(y, z));
}
