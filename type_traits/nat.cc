//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Not-a-type unittests.
 */

#include <pycpp/stl/type_traits/nat.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(nat, nat)
{
    // not instantiated, must be compile-time only
    // has no constructors or destructors, ignore
}
