//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `chrono::ceil` unittests.
 */

#include <pycpp/stl/chrono/ceil.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TEST
// ----

TEST(chrono, ceil)
{
    using clock_type = std::chrono::high_resolution_clock;
    using time_point_type = std::chrono::time_point<clock_type>;

    auto d1 = std::chrono::minutes{1} + std::chrono::seconds{105};
    auto d2 = chrono::ceil<std::chrono::minutes>(d1);
    EXPECT_EQ(d2, std::chrono::minutes{3});

    time_point_type t1(d1);
    time_point_type t2 = chrono::ceil<std::chrono::minutes>(t1);
    EXPECT_EQ(t2, time_point_type(d2));
}
