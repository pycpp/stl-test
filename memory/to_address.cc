//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `to_address` backport unittests.
 */

#include <pycpp/stl/memory/to_address.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(memory, to_address)
{
    int* p = nullptr;
    EXPECT_EQ(p, to_address(p));
}

