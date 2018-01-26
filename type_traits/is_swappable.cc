//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_swappable` unittests.
 */

#include <pycpp/stl/type_traits/is_swappable.h>
#include <gtest/gtest.h>
#include <string>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct throwing
{
    // explicitly provide all the constructors so `std::swap` doesn't
    // think it can do a noexcept swap
    throwing()
    {}

    throwing(
        const throwing&
    )
    {}

    throwing(
        throwing&&
    )
    {}

    throwing&
    operator=(
        const throwing&
    )
    {
        return *this;
    }

    throwing&
    operator=(
        throwing&&
    )
    {
        return *this;
    }
};

struct non_throwing
{};


struct throwing_member: throwing
{
    using throwing::throwing;
    void swap(throwing_member&) {}
};


struct non_throwing_member: non_throwing
{
    using non_throwing::non_throwing;
    void swap(non_throwing_member&) noexcept {}
};


struct non_swappable
{
    non_swappable() = delete;
    non_swappable(const non_swappable&) = delete;
    non_swappable& operator=(const non_swappable&) = delete;
    non_swappable(non_swappable&&) = delete;
    non_swappable& operator=(non_swappable&&) = delete;
};

void swap(
    throwing& lhs,
    throwing& rhs
);

void swap(
    non_throwing& lhs,
    non_throwing& rhs
)
noexcept;

// TESTS
// -----

TEST(is_swappable, is_swappable_with)
{
    // non-references aren't swappable
    static_assert(!is_swappable_with<int, int>::value, "");
    static_assert(!is_swappable_with<std::string, std::string>::value, "");

    static_assert(is_swappable_with<int&, int&>::value, "");
    static_assert(is_swappable_with<std::string&, std::string&>::value, "");

    // different types
    static_assert(!is_swappable_with<int, std::string>::value, "");

#ifdef HAVE_CPP14
    static_assert(is_swappable_v<int&, int&>, "");
#endif
}


TEST(is_swappable, is_nothrow_swappable_with)
{
    static_assert(!is_nothrow_swappable_with<throwing&, throwing&>::value, "");
    static_assert(is_nothrow_swappable_with<non_throwing&, non_throwing&>::value, "");
    static_assert(!is_nothrow_swappable_with<throwing&, non_throwing&>::value, "");

#ifdef HAVE_CPP14
    static_assert(is_nothrow_swappable_with_v<non_throwing&, non_throwing&>, "");
#endif
}


TEST(is_swappable, is_swappable)
{
    static_assert(is_swappable<int>::value, "");
    static_assert(is_swappable<std::string>::value, "");
    static_assert(is_swappable<throwing>::value, "");
    static_assert(is_swappable<non_throwing>::value, "");
    static_assert(!is_swappable<non_swappable>::value, "");

#ifdef HAVE_CPP14
    static_assert(is_swappable_v<int>, "");
#endif
}


TEST(is_swappable, is_nothrow_swappable)
{
    static_assert(is_nothrow_swappable<int>::value, "");
    static_assert(is_nothrow_swappable<std::string>::value, "");
    static_assert(!is_nothrow_swappable<throwing>::value, "");
    static_assert(is_nothrow_swappable<non_throwing>::value, "");
    static_assert(!is_nothrow_swappable<non_swappable>::value, "");

#ifdef HAVE_CPP14
    static_assert(is_nothrow_swappable_v<int>, "");
#endif
}


TEST(is_swappable, is_member_swappable)
{
    static_assert(!is_member_swappable<int>::value, "");
    static_assert(is_member_swappable<std::string>::value, "");
    static_assert(!is_member_swappable<throwing>::value, "");
    static_assert(!is_member_swappable<non_throwing>::value, "");
    static_assert(is_member_swappable<throwing_member>::value, "");
    static_assert(is_member_swappable<non_throwing_member>::value, "");

#ifdef HAVE_CPP14
    static_assert(is_member_swappable_v<std::string>, "");
#endif
}


TEST(is_swappable, is_nothrow_member_swappable)
{
    static_assert(!is_nothrow_member_swappable<int>::value, "");
    static_assert(!is_nothrow_member_swappable<throwing>::value, "");
    static_assert(!is_nothrow_member_swappable<non_throwing>::value, "");
    static_assert(!is_nothrow_member_swappable<throwing_member>::value, "");
    static_assert(is_nothrow_member_swappable<non_throwing_member>::value, "");

#ifdef HAVE_CPP14
    static_assert(is_nothrow_member_swappable_v<non_throwing_member>, "");
#endif
}


TEST(is_swappable, enable_swappable_with)
{
    using t1 = typename enable_swappable_with<int&, int&>::type;
    using t2 = enable_swappable_with_t<int&, int&>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_swappable, enable_nothrow_swappable_with)
{
    using t1 = typename enable_nothrow_swappable_with<int&, int&>::type;
    using t2 = enable_nothrow_swappable_with_t<int&, int&>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_swappable, enable_swappable)
{
    using t1 = typename enable_swappable<int>::type;
    using t2 = enable_swappable_t<int>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_swappable, enable_nothrow_swappable)
{
    using t1 = typename enable_nothrow_swappable<int>::type;
    using t2 = enable_nothrow_swappable_t<int>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_swappable, enable_member_swappable)
{
    using t1 = typename enable_member_swappable<throwing_member>::type;
    using t2 = enable_member_swappable_t<throwing_member>;
    static_assert(std::is_same<t1, t2>::value, "");
}


TEST(is_swappable, enable_nothrow_member_swappable)
{
    using t1 = typename enable_nothrow_member_swappable<non_throwing_member>::type;
    using t2 = enable_nothrow_member_swappable_t<non_throwing_member>;
    static_assert(std::is_same<t1, t2>::value, "");
}

