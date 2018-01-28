//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Logical type operator unittests.
 */

#include <pycpp/stl/type_traits/identity.h>
#include <pycpp/stl/type_traits/logical.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(logical, type_map_and)
{
    static_assert(type_map_and<identity_t, std::true_type>::value, "");
    static_assert(!type_map_and<identity_t, std::false_type>::value, "");
    static_assert(type_map_and<identity_t, std::true_type, std::true_type>::value, "");
    static_assert(!type_map_and<identity_t, std::true_type, std::false_type>::value, "");
    static_assert(!type_map_and<identity_t, std::false_type, std::false_type>::value, "");

#if PYCPP_CPP14
    static_assert(type_map_and_v<identity_t, std::true_type>, "");
#endif
}


TEST(logical, type_map_or)
{
    static_assert(type_map_or<identity_t, std::true_type>::value, "");
    static_assert(!type_map_or<identity_t, std::false_type>::value, "");
    static_assert(type_map_or<identity_t, std::true_type, std::true_type>::value, "");
    static_assert(type_map_or<identity_t, std::true_type, std::false_type>::value, "");
    static_assert(!type_map_or<identity_t, std::false_type, std::false_type>::value, "");

#if PYCPP_CPP14
    static_assert(type_map_or_v<identity_t, std::true_type>, "");
#endif
}


TEST(logical, type_not)
{
    static_assert(type_not<identity_t, std::false_type>::value, "");
    static_assert(!type_not<identity_t, std::true_type>::value, "");

#if PYCPP_CPP14
    static_assert(type_not_v<identity_t, std::false_type>, "");
#endif
}

// TODO:
