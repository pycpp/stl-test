//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_aggregate` unittests.
 */

#include <pycpp/stl/type_traits/is_aggregate.h>
#include <gtest/gtest.h>
#include <type_traits>

PYCPP_USING_NAMESPACE

// DATA

struct pod_struct
{};

class virtual_class
{
    virtual ~virtual_class();
};

// TESTS
// -----

TEST(is_aggregate, is_aggregate)
{
    static_assert(!is_aggregate<int>::value, "");
    static_assert(is_aggregate<int[5]>::value, "");
    static_assert(is_aggregate<pod_struct>::value, "");
    static_assert(!is_aggregate<virtual_class>::value, "");
#ifdef HAVE_CPP14
    static_assert(!is_aggregate_v<int>, "");
    static_assert(is_aggregate_v<int[5]>, "");
    static_assert(is_aggregate_v<pod_struct>, "");
    static_assert(!is_aggregate_v<virtual_class>, "");
#endif
}
