//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Member function detection unittests.
 */

#include <pycpp/stl/type_traits/has_member_function.h>
#include <gtest/gtest.h>
#include <deque>
#include <unordered_set>
#include <vector>

PYCPP_USING_NAMESPACE

// DATA
// ----

PYCPP_HAS_MEMBER_FUNCTION(reserve, has_reserve);
PYCPP_HAS_MEMBER_FUNCTION(push_back, has_push_back, void (C::*)(typename C::const_reference));

// TESTS
// -----

TEST(has_member_function, has_reserve)
{
    using deq = std::deque<int>;
    using vec = std::vector<int>;

    static_assert(!has_reserve<deq>::value, "");
    static_assert(has_reserve<vec>::value, "");
}


TEST(has_member_function, has_push_back)
{
    using set = std::unordered_set<int>;
    using vec = std::vector<int>;

    static_assert(!has_push_back<set>::value, "");
    static_assert(has_push_back<vec>::value, "");
}
