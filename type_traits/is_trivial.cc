//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_trivial` unittests.
 */

#include <pycpp/stl/type_traits/is_trivial.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct virtual_struct
{
    virtual ~virtual_struct();
};

struct incomplete;

// TESTS
// -----

TEST(is_trivial, is_trivially_copyable)
{
    static_assert(is_trivially_copyable<int>::value, "");
    static_assert(!is_trivially_copyable<virtual_struct>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_trivially_copyable_v<int>, "");
#endif
}


TEST(is_trivial, is_trivially_constructible)
{
    static_assert(is_trivially_constructible<int>::value, "");
    static_assert(!is_trivially_constructible<virtual_struct>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_trivially_constructible_v<int>, "");
#endif
}


TEST(is_trivial, is_trivially_default_constructible)
{
    static_assert(is_trivially_default_constructible<int>::value, "");
    static_assert(!is_trivially_default_constructible<virtual_struct>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_trivially_default_constructible_v<int>, "");
#endif
}


TEST(is_trivial, is_trivially_copy_constructible)
{
    static_assert(is_trivially_copy_constructible<int>::value, "");
    static_assert(!is_trivially_copy_constructible<virtual_struct>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_trivially_copy_constructible_v<int>, "");
#endif
}


TEST(is_trivial, is_trivially_move_constructible)
{
    static_assert(is_trivially_move_constructible<int>::value, "");
    static_assert(!is_trivially_move_constructible<virtual_struct>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_trivially_move_constructible_v<int>, "");
#endif
}


TEST(is_trivial, is_trivially_assignable)
{
    static_assert(is_trivially_assignable<int&, int>::value, "");
    static_assert(!is_trivially_assignable<virtual_struct&, virtual_struct>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_trivially_assignable_v<int&, int>, "");
#endif
}


TEST(is_trivial, is_trivially_copy_assignable)
{
    static_assert(is_trivially_copy_assignable<int>::value, "");
    static_assert(!is_trivially_copy_assignable<virtual_struct>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_trivially_copy_assignable_v<int>, "");
#endif
}


TEST(is_trivial, is_trivially_move_assignable)
{
    static_assert(is_trivially_move_assignable<int>::value, "");
    static_assert(!is_trivially_move_assignable<virtual_struct>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_trivially_move_assignable_v<int>, "");
#endif
}


TEST(is_trivial, enable_trivially_copyable)
{
    using t1 = typename enable_trivially_copyable<int, int>::type;
    using t2 = enable_trivially_copyable_t<int, int>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_trivial, enable_trivially_constructible)
{
    using t1 = typename enable_trivially_constructible<int, int>::type;
    using t2 = enable_trivially_constructible_t<int, int>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_trivial, enable_trivially_default_constructible)
{
    using t1 = typename enable_trivially_default_constructible<int, int>::type;
    using t2 = enable_trivially_default_constructible_t<int, int>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_trivial, enable_trivially_copy_constructible)
{
    using t1 = typename enable_trivially_copy_constructible<int, int>::type;
    using t2 = enable_trivially_copy_constructible_t<int, int>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_trivial, enable_trivially_move_constructible)
{
    using t1 = typename enable_trivially_move_constructible<int, int>::type;
    using t2 = enable_trivially_move_constructible_t<int, int>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_trivial, enable_trivially_assignable)
{
    using t1 = typename enable_trivially_assignable<int&, int, int>::type;
    using t2 = enable_trivially_assignable_t<int&, int, int>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_trivial, enable_trivially_copy_assignable)
{
    using t1 = typename enable_trivially_copy_assignable<int, int>::type;
    using t2 = enable_trivially_copy_assignable_t<int, int>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_trivial, enable_trivially_move_assignable)
{
    using t1 = typename enable_trivially_move_assignable<int, int>::type;
    using t2 = enable_trivially_move_assignable_t<int, int>;
    static_assert(std::is_same<t1, t2>::value, "");
}
