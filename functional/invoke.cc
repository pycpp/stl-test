//  :copyright: (c) 2009-2017 LLVM Team.
//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief C++17 invoke backport unittests.
 */

#include <pycpp/stl/functional/invoke.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

template <typename T, int N>
struct array_type
{
    typedef T type[N];
};

struct type
{
    array_type<char, 1>::type& f1();
    array_type<char, 2>::type& f2() const;
    array_type<char, 1>::type& g1() &;
    array_type<char, 2>::type& g2() const&;
    array_type<char, 3>::type& g3() &&;
    array_type<char, 4>::type& g4() const&&;
};

// TESTS
// -----

TEST(functional, invoke)
{
    static_assert(sizeof(invoke(&type::f1, std::declval<type >())) == 1, "");
    static_assert(sizeof(invoke(&type::f2, std::declval<const type>())) == 2, "");
    static_assert(sizeof(invoke(&type::g1, std::declval<type&>())) == 1, "");
    static_assert(sizeof(invoke(&type::g2, std::declval<const type&>())) == 2, "");
    static_assert(sizeof(invoke(&type::g3, std::declval<type &&>())) == 3, "");
    static_assert(sizeof(invoke(&type::g4, std::declval<const type&&>())) == 4, "");
}
