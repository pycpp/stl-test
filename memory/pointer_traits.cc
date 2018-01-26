//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `pointer_traits` backport unittests.
 */

#include <pycpp/stl/memory/pointer_traits.h>
#include <gtest/gtest.h>
#include <type_traits>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(memory, pointer_traits)
{
    using traits = pointer_traits<int*>;
    static_assert(std::is_same<int*, typename traits::pointer>::value, "");
    static_assert(std::is_same<int, typename traits::element_type>::value, "");

    int* p = nullptr;
    EXPECT_EQ(p, traits::to_address(p));
}

