//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `has_is_always_equal` unittests.
 */

#include <pycpp/stl/type_traits/has_is_always_equal.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct yes_test
{
    using is_always_equal = std::true_type;
};

struct no_test
{
    int is_always_equal = 5;
};

// TESTS
// -----

TEST(type_traits, has_is_always_equal)
{
    static_assert(has_is_always_equal<yes_test>::value, "");
    static_assert(!has_is_always_equal<no_test>::value, "");

#ifdef PYCPP_CPP14
    static_assert(has_is_always_equal_v<yes_test>, "");
#endif
}
