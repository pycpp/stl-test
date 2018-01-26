//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Custom deleter for smart pointer unittests.
 */

#include <pycpp/stl/memory/allocator.h>
#include <pycpp/stl/memory/allocator_destructor.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(allocator_destructor, allocator_destructor)
{
    using allocator_type = allocator<int>;
    using traits = allocator_traits<allocator_type>;
    using deleter = allocator_destructor<allocator_type>;

    allocator_type alloc;
    std::unique_ptr<int, deleter> h(traits::allocate(alloc, 1), deleter(alloc, 1));
    traits::construct(alloc, h.get(), 5);
    EXPECT_EQ(*h, 5);
}




