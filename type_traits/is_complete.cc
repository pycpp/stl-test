//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_complete` unittests.
 */

#include <pycpp/stl/type_traits/is_complete.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct pod_struct
{};

struct incomplete;

// TESTS
// -----

TEST(is_complete, is_complete)
{
    static_assert(is_complete<int>::value, "");
    static_assert(is_complete<int[5]>::value, "");
    static_assert(is_complete<pod_struct>::value, "");
    static_assert(!is_complete<incomplete>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_complete_v<int>, "");
    static_assert(is_complete_v<int[5]>, "");
    static_assert(is_complete_v<pod_struct>, "");
    static_assert(!is_complete_v<incomplete>, "");
#endif
}
