//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Member function `construct` detection unittests.
 */

#include <pycpp/stl/memory/has_construct.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

template <typename T>
struct with_construct
{
    using value_type = T;

    T* allocate(std::size_t n);
    void deallocate(T* p, std::size_t n);

    template <typename ... Ts >
    static void construct(T* p, Ts&&... ts);
};

template <typename T>
struct without_construct
{
    using value_type = T;

    T* allocate(std::size_t n);
    void deallocate(T* p, std::size_t n);
};

// TESTS
// -----

TEST(memory, has_construct)
{
    using a1 = with_construct<int>;
    using a2 = without_construct<int>;
    static_assert(has_construct<a1, int>::value, "");
    static_assert(!has_construct<a2, int>::value, "");
#ifdef PYCPP_CPP14
    static_assert(has_construct_v<a1, int>, "");
#endif
}


TEST(memory, has_memcpy_construct)
{
    using a1 = with_construct<int>;
    using a2 = without_construct<int>;
    static_assert(has_memcpy_construct<a1, int>::value, "");
    static_assert(has_memcpy_construct<a2, int>::value, "");
#ifdef PYCPP_CPP14
    static_assert(has_memcpy_construct_v<a1, int>, "");
#endif
}


TEST(memory, enable_memcpy_construct)
{
    using alloc = with_construct<int>;
    using t1 = typename enable_memcpy_construct<alloc, int>::type;
    using t2 = enable_memcpy_construct_t<alloc, int>;
    static_assert(std::is_same<t1, t2>::value, "");
}
