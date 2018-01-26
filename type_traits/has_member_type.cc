//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Member type detection unittests.
 */

#include <pycpp/stl/type_traits/has_member_type.h>
#include <gtest/gtest.h>
#include <map>
#include <vector>

PYCPP_USING_NAMESPACE

// DATA
// ----

PYCPP_HAS_MEMBER_TYPE(mapped_type, has_mapped_type);

// TESTS
// -----

TEST(has_member_type, has_mapped_type)
{
    using map_type = std::map<int, int>;
    using vector_type = std::vector<int>;

    static_assert(has_mapped_type<map_type>::value, "");
    static_assert(!has_mapped_type<vector_type>::value, "");
}
