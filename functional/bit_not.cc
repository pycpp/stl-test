//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Bitwise negation functor unittests.
 */

#include <pycpp/stl/functional/bit_not.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, bit_not)
{
    EXPECT_EQ(bit_not<int>()(1), -2);
    EXPECT_EQ(bit_not<int>()(2), -3);
}
