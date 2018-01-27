//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief <deque> unittests.
 */

#include <pycpp/stl/deque.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(deque, deque)
{
    using deque_type = deque<int, allocator<int>>;
//    deque<int> x;
    // TODO: need to fix...
//    EXPECT_TRUE(x.empty());
}
