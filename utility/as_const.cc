//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `as_const` backport unittests.
 */

#include <pycpp/stl/utility/as_const.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(utility, as_const)
{
    int x = 5;
    const int& y = as_const(x);
    EXPECT_EQ(x, y);
}
