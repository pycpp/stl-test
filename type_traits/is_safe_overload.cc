//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_safe_overload` unittests.
 */

#include <pycpp/stl/type_traits/is_safe_overload.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(is_safe_overload, is_safe_overload)
{
    static_assert(!is_safe_overload<false, int, int>::value, "");
    static_assert(!is_safe_overload<false, int, int, std::allocator<int>>::value, "");
    static_assert(is_safe_overload<false, int, const int&, std::allocator<int>>::value, "");
    static_assert(is_safe_overload<false, int, float>::value, "");
    static_assert(!is_safe_overload<true, int, int, std::allocator<int>>::value, "");
    static_assert(!is_safe_overload<true, int, const int&, std::allocator<int>>::value, "");
    static_assert(is_safe_overload<true, int, float>::value, "");

#ifdef HAVE_CPP14
    static_assert(!is_safe_overload_v<false, int, int>, "");
    static_assert(!is_safe_overload_v<false, int, int, std::allocator<int>>, "");
    static_assert(is_safe_overload_v<false, int, const int&, std::allocator<int>>, "");
    static_assert(!is_safe_overload_v<true, int, int, std::allocator<int>>, "");
    static_assert(!is_safe_overload_v<true, int, const int&, std::allocator<int>>, "");
#endif
}


TEST(is_safe_overload, enable_safe_overload)
{
    using t1 = typename enable_safe_overload<true, int, float>::type;
    using t2 = enable_safe_overload_t<true, int, float>;
    static_assert(std::is_same<t1, t2>::value, "");
}
