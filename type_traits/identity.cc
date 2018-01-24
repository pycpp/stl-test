//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `identity` unittests.
 */

#include <pycpp/stl/type_traits/identity.h>
#include <gtest/gtest.h>
#include <type_traits>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(identity, identity)
{
    static_assert(std::is_same<typename identity<int>::type, int>::value, "");
    static_assert(std::is_same<identity_t<int>, int>::value, "");
}
