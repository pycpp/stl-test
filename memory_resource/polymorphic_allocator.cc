//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see licenses/mit.md for more details.

#include <pycpp/stl/memory_resource/polymorphic_allocator.h>
#include <gtest/gtest.h>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----


TEST(polymorphic, is_relocatable)
{
    using allocator_type = pmr::polymorphic_allocator<char>;
    static_assert(is_relocatable<pmr::memory_resource>::value, "");
    static_assert(is_relocatable<allocator_type>::value, "");
}


TEST(polymorphic_allocator, polymorphic_allocator)
{
    using allocator_type = pmr::polymorphic_allocator<char>;
    allocator_type allocator;

    char* ptr = allocator.allocate(50);
    allocator.deallocate(ptr, 50);

    ptr = allocator.allocate(50);
    allocator.deallocate(ptr, 50);
}


TEST(polymorphic_allocator, new_delete_resource)
{
    using allocator_type = pmr::polymorphic_allocator<char>;
    allocator_type allocator(pmr::new_delete_resource());

    char* ptr = allocator.allocate(50);
    allocator.deallocate(ptr, 50);

    ptr = allocator.allocate(50);
    allocator.deallocate(ptr, 50);
}


TEST(polymorphic_allocator, null_memory_resource)
{
    using allocator_type = pmr::polymorphic_allocator<char>;
    allocator_type allocator(pmr::null_memory_resource());

    EXPECT_THROW(allocator.allocate(50), std::bad_alloc);
}


TEST(polymorphic_allocator, vector)
{
    using allocator_type = pmr::polymorphic_allocator<int>;
    using vector_type = std::vector<int, allocator_type>;

    vector_type v1;
    v1.emplace_back(1);
}
