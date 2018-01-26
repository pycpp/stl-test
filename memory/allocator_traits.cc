//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief allocator trait unittests.
 */

#include <pycpp/stl/memory/allocator.h>
#include <pycpp/stl/memory/allocator_traits.h>
#include <gtest/gtest.h>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(allocator_traits, typedefs)
{
    // check core typedefs work
    using allocator_type = allocator<int>;
    using traits = allocator_traits<allocator_type>;
    using value_type = traits::value_type;
    using pointer = traits::pointer;
    using void_pointer = traits::void_pointer;
    using size_type = traits::size_type;
    using difference_type = traits::difference_type;
}


TEST(allocator_traits, reallocate)
{
    using allocator_type = allocator<int>;
    using traits = allocator_traits<allocator_type>;
    using value_type = traits::value_type;
    using size_type = traits::size_type;

    // allocate memory
    size_type size = 10;
    allocator_type alloc;
    value_type* p = traits::allocate(alloc, size);
    for (size_type i = 0; i < size; ++i) {
        traits::construct(alloc, &p[i], 2 * static_cast<value_type>(i));
    }

    // reallocate
    size_type new_size = 30;
    size_type count = size;
    p = traits::reallocate(alloc, p, size, new_size, count);
    for (size_type i = 0; i < count; ++i) {
        EXPECT_EQ(static_cast<value_type>(2*i), p[i]);
    }

    // free
    for (size_type i = 0; i < size; ++i) {
        traits::destroy(alloc, &p[i]);
    }
    traits::deallocate(alloc, p, new_size);
}


TEST(allocator_traits, construct_forward)
{
    using allocator_type = allocator<int>;
    using traits = allocator_traits<allocator_type>;
    using value_type = traits::value_type;
    std::vector<value_type, allocator_type> v ={1, 2, 3, 4, 5};

    allocator_type alloc;
    value_type* p = traits::allocate(alloc, v.size());
    value_type* pl = p;
    traits::construct_forward(alloc, v.data(), v.data() + v.size(), pl);
    EXPECT_EQ(p + v.size(), pl);
    for (size_t i = 0; i < v.size(); ++i) {
        EXPECT_EQ(p[i], i+1);
    }
    traits::deallocate(alloc, p, v.size());
}


TEST(allocator_traits, construct_range_forward)
{
    using allocator_type = allocator<int>;
    using traits = allocator_traits<allocator_type>;
    using value_type = traits::value_type;
    std::vector<value_type, allocator_type> v ={1, 2, 3, 4, 5};

    allocator_type alloc;
    value_type* p = traits::allocate(alloc, v.size());
    value_type* pl = p;
    traits::construct_range_forward(alloc, v.data(), v.data() + v.size(), pl);
    EXPECT_EQ(p + v.size(), pl);
    for (size_t i = 0; i < v.size(); ++i) {
        EXPECT_EQ(p[i], i+1);
    }
    traits::deallocate(alloc, p, v.size());
}


TEST(allocator_traits, construct_backward)
{
    using allocator_type = allocator<int>;
    using traits = allocator_traits<allocator_type>;
    using value_type = traits::value_type;
    std::vector<value_type, allocator_type> v ={1, 2, 3, 4, 5};

    allocator_type alloc;
    value_type* p = traits::allocate(alloc, v.size());
    value_type* pl = p + v.size();
    traits::construct_backward(alloc, v.data(), v.data() + v.size(), pl);
    EXPECT_EQ(p, pl);
    for (size_t i = 0; i < v.size(); ++i) {
        EXPECT_EQ(p[i], i+1);
    }
    traits::deallocate(alloc, p, v.size());
}
