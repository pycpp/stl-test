//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_duration` unittests.
 */

#include <pycpp/stl/type_traits/is_duration.h>
#include <gtest/gtest.h>
#include <chrono>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(is_duration, is_duration)
{
    using duration_type = std::chrono::duration<int>;
    static_assert(is_duration<duration_type>::value, "");
    static_assert(is_duration<const duration_type>::value, "");
    static_assert(is_duration<volatile duration_type>::value, "");
    static_assert(is_duration<duration_type&>::value, "");
    static_assert(is_duration<const duration_type&>::value, "");
    static_assert(is_duration<const volatile duration_type&>::value, "");

#if PYCPP_CPP14
    static_assert(is_duration_v<duration_type>, "");
#endif
}
