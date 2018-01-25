//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `lcm` unittests.
 */

#include <pycpp/stl/numeric/lcm.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(numeric, lcm)
{
    static_assert(lcm(2, 3) == 6, "");
    static_assert(lcm(2, 4) == 4, "");
    static_assert(lcm(16, 4) == 16, "");
}
