//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `uses_allocator` unittests.
 */

#include <pycpp/stl/memory/uses_allocator.h>
#include <gtest/gtest.h>
#include <string>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(memory, uses_allocator)
{
    using allocator_type = typename std::string::allocator_type;
    static_assert(uses_allocator<std::string, allocator_type>::value, "");
    static_assert(!uses_allocator<int, allocator_type>::value, "");
}
