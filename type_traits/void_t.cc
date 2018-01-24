//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `void_t` unittests.
 */

#include <pycpp/stl/type_traits/void_t.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(void_t, void_t)
{
    static_assert(std::is_same<void_t<>, void>::value, "");
    static_assert(std::is_same<void_t<int>, void>::value, "");
    static_assert(std::is_same<void_t<int, float>, void>::value, "");
    static_assert(std::is_same<void_t<int, float, void_t<>>, void>::value, "");
}
