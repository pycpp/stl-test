//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `abs` unittests.
 */

#include <pycpp/stl/numeric/abs.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(numeric, abs_constexpr)
{
    abs_constexpr<int, int> caller;
    static_assert(caller(-1) == 1, "");
    static_assert(caller(-5) == 5, "");
    static_assert(caller(25) == 25, "");
}
