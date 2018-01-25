//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief C++17 not_fn backport unittests.
 */

#include <pycpp/stl/functional/not_fn.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(functional, not_fn)
{
    auto call = [](int x) -> bool
    {
        return static_cast<bool>(x);
    };

    auto not_call = not_fn(call);
    EXPECT_FALSE(call(0));
    EXPECT_TRUE(call(1));
    EXPECT_TRUE(not_call(0));
    EXPECT_FALSE(not_call(1));
}
