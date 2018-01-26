//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief C++11 backport for `make_unique` unittests.
 */

#include <pycpp/stl/memory/make_unique.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(memory, make_unique)
{
    auto p = make_unique<int>(1);
    ASSERT_TRUE(p);
    EXPECT_EQ(*p, 1);
    p.reset();
    ASSERT_FALSE(p);
}
