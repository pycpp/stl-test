//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `to_raw_pointer` helper unittests.
 */

#include <pycpp/stl/memory/to_raw_pointer.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(memory, to_raw_pointer)
{
    int* p = nullptr;
    EXPECT_EQ(p, to_raw_pointer(p));
}

