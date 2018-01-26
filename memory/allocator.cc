//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief General-purpose allocator unittests.
 */

#include <pycpp/stl/memory/allocator.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(memory, allocator)
{
    using allocator_type = allocator<int>;
    allocator_type alloc;
    int* p = allocate_and_construct<int>(alloc, 5);
    EXPECT_EQ(*p, 5);
    destroy_and_deallocate(alloc, p);
}
