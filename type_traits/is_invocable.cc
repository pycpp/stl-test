//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_invocable` unittests.
 */

#include <pycpp/stl/type_traits/is_invocable.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// FUNCTIONS
// ---------

void
throwing(int);

void
non_throwing(int)
noexcept;

// TESTS
// -----

TEST(is_invocable, is_invocable)
{
    static_assert(is_invocable<int()>::value, "");
    static_assert(is_invocable<decltype(throwing), int>::value, "");
    static_assert(!is_invocable<decltype(throwing), void*>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_invocable_v<int()>, "");
    static_assert(is_invocable_v<decltype(throwing), int>, "");
    static_assert(!is_invocable_v<decltype(throwing), void*>, "");
#endif
}


TEST(is_invocable, is_invocable_r)
{
    static_assert(is_invocable_r<int, int()>::value, "");
    static_assert(!is_invocable_r<void*, int()>::value, "");
    static_assert(is_invocable_r<void, decltype(throwing), int>::value, "");
    static_assert(!is_invocable_r<int, decltype(throwing), int>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_invocable_r_v<int, int()>, "");
    static_assert(!is_invocable_r_v<void*, int()>, "");
    static_assert(is_invocable_r_v<void, decltype(throwing), int>, "");
    static_assert(!is_invocable_r_v<int, decltype(throwing), int>, "");
#endif
}


TEST(is_invocable, is_nothrow_invocable)
{
#ifdef HAVE_CPP17
    static_assert(!is_nothrow_invocable<decltype(throwing), int>::value, "");
    static_assert(is_nothrow_invocable<decltype(non_throwing), int>::value, "");
    static_assert(!is_nothrow_invocable<decltype(throwing), void*>::value, "");
    static_assert(!is_nothrow_invocable<decltype(non_throwing), void*>::value, "");

    static_assert(!is_nothrow_invocable_v<decltype(throwing), int>, "");
    static_assert(is_nothrow_invocable_v<decltype(non_throwing), int>, "");
    static_assert(!is_nothrow_invocable_v<decltype(throwing), void*>, "");
    static_assert(!is_nothrow_invocable_v<decltype(non_throwing), void*>, "");
#endif
}


TEST(is_invocable, is_nothrow_invocable_r)
{
#ifdef HAVE_CPP17
    static_assert(!is_nothrow_invocable_r<void, decltype(throwing), int>::value, "");
    static_assert(is_nothrow_invocable_r<void, decltype(non_throwing), int>::value, "");
    static_assert(!is_nothrow_invocable_r<int, decltype(non_throwing), int>::value, "");
    static_assert(!is_nothrow_invocable_r<void, decltype(throwing), void*>::value, "");
    static_assert(!is_nothrow_invocable_r<void, decltype(non_throwing), void*>::value, "");

    static_assert(!is_nothrow_invocable_r_v<void, decltype(throwing), int>, "");
    static_assert(is_nothrow_invocable_r_v<void, decltype(non_throwing), int>, "");
    static_assert(!is_nothrow_invocable_r_v<int, decltype(non_throwing), int>, "");
    static_assert(!is_nothrow_invocable_r_v<void, decltype(throwing), void*>, "");
    static_assert(!is_nothrow_invocable_r_v<void, decltype(non_throwing), void*>, "");
#endif
}


TEST(is_invocable, invoke_result)
{
    static_assert(std::is_same<invoke_result_t<int()>, int>::value, "");
    static_assert(!std::is_same<invoke_result_t<decltype(throwing), int>, int>::value, "");
    static_assert(std::is_same<invoke_result_t<decltype(throwing), int>, void>::value, "");
}
