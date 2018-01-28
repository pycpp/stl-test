//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_reference_wrapper` unittests.
 */

#include <pycpp/stl/type_traits/is_reference_wrapper.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct pod_struct
{};

struct incomplete;

// TESTS
// -----

TEST(is_reference_wrapper, is_reference_wrapper)
{
    static_assert(!is_reference_wrapper<int>::value, "");
    static_assert(!is_reference_wrapper<int&>::value, "");
    static_assert(!is_reference_wrapper<int&&>::value, "");
    static_assert(!is_reference_wrapper<int*>::value, "");
    static_assert(!is_reference_wrapper<int*&>::value, "");
    static_assert(!is_reference_wrapper<int*&&>::value, "");
    static_assert(is_reference_wrapper<std::reference_wrapper<int>>::value, "");
    static_assert(is_reference_wrapper<std::reference_wrapper<int>&>::value, "");
    static_assert(is_reference_wrapper<std::reference_wrapper<int>&&>::value, "");
    static_assert(is_reference_wrapper<const std::reference_wrapper<int>>::value, "");
    static_assert(is_reference_wrapper<volatile std::reference_wrapper<int>>::value, "");
    static_assert(is_reference_wrapper<const volatile std::reference_wrapper<int>>::value, "");
    static_assert(is_reference_wrapper<const volatile std::reference_wrapper<int>&>::value, "");
#ifdef PYCPP_CPP14
    static_assert(!is_reference_wrapper_v<int>, "");
    static_assert(!is_reference_wrapper_v<int&>, "");
    static_assert(!is_reference_wrapper_v<int&&>, "");
    static_assert(!is_reference_wrapper_v<int*>, "");
    static_assert(!is_reference_wrapper_v<int*&>, "");
    static_assert(!is_reference_wrapper_v<int*&&>, "");
    static_assert(is_reference_wrapper_v<std::reference_wrapper<int>>, "");
    static_assert(is_reference_wrapper_v<std::reference_wrapper<int>&>, "");
    static_assert(is_reference_wrapper_v<std::reference_wrapper<int>&&>, "");
    static_assert(is_reference_wrapper_v<const std::reference_wrapper<int>>, "");
    static_assert(is_reference_wrapper_v<volatile std::reference_wrapper<int>>, "");
    static_assert(is_reference_wrapper_v<const volatile std::reference_wrapper<int>>, "");
    static_assert(is_reference_wrapper_v<const volatile std::reference_wrapper<int>&>, "");
#endif
}
