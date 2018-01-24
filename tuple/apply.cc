//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `apply` backport unittests.
 */

#include <pycpp/stl/tuple/apply.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(tuple, apply)
{
    auto add = [](int x, int y) -> int
    {
        return x + y;
    };

    EXPECT_EQ(apply(add, std::make_tuple(1, 2)), 3);
}
