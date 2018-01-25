//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `gcd` unittests.
 */

#include <pycpp/stl/numeric/gcd.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(numeric, gcd)
{
    static_assert(gcd(2, 3) == 1, "");
    static_assert(gcd(2, 4) == 2, "");
    static_assert(gcd(16, 4) == 4, "");
}

