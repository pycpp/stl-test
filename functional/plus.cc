//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type-deducing plus unittests.
 */

#include <pycpp/stl/functional/plus.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, plus)
{
    int x = 1;
    int y = 2;
    int z = 3;
    plus<> op;
    EXPECT_EQ(op(x, y), 3);
    EXPECT_EQ(op(x, z), 4);
    EXPECT_EQ(op(y, z), 5);
}
