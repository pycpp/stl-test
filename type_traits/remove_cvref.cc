//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `remove_cvref` unittests.
 */

#include <pycpp/stl/type_traits/remove_cvref.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(remove_cvref, remove_cvref)
{
    static_assert(std::is_same<typename remove_cvref<int>::type, int>::value, "");
    static_assert(std::is_same<remove_cvref_t<int>, int>::value, "");
    static_assert(std::is_same<remove_cvref_t<int&>, int>::value, "");
    static_assert(std::is_same<remove_cvref_t<const int&>, int>::value, "");
    static_assert(std::is_same<remove_cvref_t<volatile int&>, int>::value, "");
    static_assert(std::is_same<remove_cvref_t<const volatile int&>, int>::value, "");
    static_assert(!std::is_same<remove_cvref_t<float>, int>::value, "");
}
