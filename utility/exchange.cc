//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `exchange` backport unittests.
 */

#include <pycpp/stl/utility/exchange.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(utility, exchange)
{
    int x = 5;
    EXPECT_EQ(exchange(x, 2), 5);
    EXPECT_EQ(x, 2);
}
