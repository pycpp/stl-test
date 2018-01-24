//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `chrono::abs` unittests.
 */

#include <pycpp/stl/chrono/abs.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TEST
// ----

TEST(chrono, abs)
{
    auto d1 = std::chrono::minutes{-1};
    auto d2 = std::chrono::minutes{1};
    EXPECT_EQ(chrono::abs(d1), d2);
    EXPECT_EQ(chrono::abs(d2), d2);
}
