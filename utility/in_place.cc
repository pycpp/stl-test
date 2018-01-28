//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `in_place` backport unittests.
 */

#include <pycpp/stl/utility/in_place.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(utility, in_place)
{
    EXPECT_TRUE(sizeof(in_place_t) >= 0);
    EXPECT_TRUE(sizeof(in_place) >= 0);
    EXPECT_TRUE(sizeof(in_place_type_t<int>) >= 0);
    EXPECT_TRUE(sizeof(in_place_index_t<0>) >= 0);
#ifdef PYCPP_CPP14
    EXPECT_TRUE(sizeof(in_place_type<int>) >= 0);
    EXPECT_TRUE(sizeof(in_place_index<0>) >= 0);
#endif
}
