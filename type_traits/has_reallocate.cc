//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `has_reallocate` unittests.
 */

#include <pycpp/stl/type_traits/has_reallocate.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// ALLOCATORS
// ----------

template <typename T>
struct stl_allocator
{
    using value_type = T;
};

template <typename T>
struct reallocate_allocator
{
    using value_type = T;
    using pointer = value_type*;
    using size_type = unsigned;

    static pointer reallocate(pointer, size_type, size_type, size_type, size_type = 0, size_type = 0);
};

template <typename T>
struct incompatible_allocator
{
    using value_type = T;
    using pointer = value_type*;
    using size_type = unsigned;

    static pointer reallocate(pointer, size_type);
};

// TESTS
// -----


TEST(has_reallocate, has_reallocate)
{
    using a1 = stl_allocator<char>;
    using a2 = reallocate_allocator<char>;
    using a3 = incompatible_allocator<char>;
    static_assert(!has_reallocate<a1>::value, "");
    static_assert(has_reallocate<a2>::value, "");
    static_assert(!has_reallocate<a3>::value, "");
#ifdef PYCPP_CPP14
    static_assert(!has_reallocate_v<a1>, "");
    static_assert(has_reallocate_v<a2>, "");
    static_assert(!has_reallocate_v<a3>, "");
#endif
}


TEST(has_reallocate, enable_reallocate)
{
    using allocator = reallocate_allocator<char>;
    using t1 = typename enable_reallocate<allocator>::type;
    using t2 = enable_reallocate_t<allocator>;
    static_assert(std::is_same<t1, t2>::value, "");
}
