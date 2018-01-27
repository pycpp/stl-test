//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `disable_if` unittests.
 */

#include <pycpp/stl/type_traits/disable_if.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(disable_if, disable_if)
{
    using a1 = typename disable_if<false>::type;
    using a2 = disable_if_t<false>;
    static_assert(std::is_same<a1, a2>::value, "");
}
