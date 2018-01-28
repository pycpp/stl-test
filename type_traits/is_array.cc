//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_array` unittests.
 */

#include <pycpp/stl/type_traits/is_array.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(is_array, is_array)
{
    using type = int;
    using unbounded_array = type[];
    using bounded_array = type[5];
    static_assert(!is_array<type>::value, "");
    static_assert(is_array<unbounded_array>::value, "");
    static_assert(is_array<bounded_array>::value, "");
    static_assert(is_array<const bounded_array>::value, "");
    static_assert(is_array<volatile bounded_array>::value, "");
    static_assert(is_array<const volatile bounded_array>::value, "");
    static_assert(!is_array<bounded_array&>::value, "");

#if PYCPP_CPP14
    static_assert(is_array_v<unbounded_array>, "");
#endif
}


TEST(is_array, is_bounded_array)
{
    using type = int;
    using unbounded_array = type[];
    using bounded_array = type[5];
    static_assert(!is_bounded_array<type>::value, "");
    static_assert(!is_bounded_array<unbounded_array>::value, "");
    static_assert(is_bounded_array<bounded_array>::value, "");
    static_assert(is_bounded_array<const bounded_array>::value, "");
    static_assert(is_bounded_array<volatile bounded_array>::value, "");
    static_assert(is_bounded_array<const volatile bounded_array>::value, "");
    static_assert(!is_bounded_array<bounded_array&>::value, "");

#if PYCPP_CPP14
    static_assert(is_bounded_array_v<bounded_array>, "");
#endif
}


TEST(is_array, is_unbounded_array)
{
    using type = int;
    using unbounded_array = type[];
    using bounded_array = type[5];
    static_assert(!is_unbounded_array<type>::value, "");
    static_assert(is_unbounded_array<unbounded_array>::value, "");
    static_assert(!is_unbounded_array<bounded_array>::value, "");
    static_assert(is_unbounded_array<const unbounded_array>::value, "");
    static_assert(is_unbounded_array<volatile unbounded_array>::value, "");
    static_assert(is_unbounded_array<const volatile unbounded_array>::value, "");
    static_assert(!is_unbounded_array<unbounded_array&>::value, "");

#if PYCPP_CPP14
    static_assert(is_unbounded_array_v<unbounded_array>, "");
#endif
}
