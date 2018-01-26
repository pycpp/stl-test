//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Member variable detection unittests.
 */

#include <pycpp/stl/type_traits/has_member_variable.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>

PYCPP_USING_NAMESPACE

// DATA
// ----

PYCPP_HAS_MEMBER_VARIABLE(npos, has_npos);

// TESTS
// -----


TEST(has_member_variable, has_npos)
{
    using string_type = std::string;
    using vector_type = std::vector<int>;

    static_assert(has_npos<string_type>::value, "");
    static_assert(!has_npos<vector_type>::value, "");
}
