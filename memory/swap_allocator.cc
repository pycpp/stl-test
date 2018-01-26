//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Specialized swap for allocator unittests.
 */

#include <pycpp/stl/memory/allocator.h>
#include <pycpp/stl/memory/swap_allocator.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(memory, swap_allocator)
{
    using allocator_type = allocator<int>;
    allocator_type a1, a2;
    swap_allocator(a1, a2);
}
