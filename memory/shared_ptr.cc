//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief shared_ptr unittests.
 */

#include <pycpp/stl/memory/allocator.h>
#include <pycpp/stl/memory/shared_ptr.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

template <bool ThreadSafe>
struct shared: enable_shared_from_this<shared<ThreadSafe>, ThreadSafe>
{
    shared_ptr<shared, ThreadSafe> create()
    {
        return this->shared_from_this();
    }
};

// HELPERS
// -------

template <typename T, bool ThreadSafe>
static
void
test_constructors()
{
    using type = T;
    using const_type = typename std::add_const<T>::type;
    using shared_type = shared_ptr<type, ThreadSafe>;
    using alias_type = shared_ptr<const_type, ThreadSafe>;
    using deleter_type = std::default_delete<type>;
    using allocator_type = std::allocator<type>;

    type x = 5;
    alias_type a1;
    alias_type a2(new const_type(2));

    // shared_ptr constructors
    shared_type s1;
    shared_type s2(nullptr);
    alias_type s3(new type(3));
    alias_type s4(new type(4), deleter_type());
    shared_type s5(nullptr, deleter_type());
    shared_type s6(new type(6), deleter_type(), allocator_type());
    shared_type s7(nullptr, deleter_type(), allocator_type());
    shared_type s8(s1, &x);
    shared_type s9(s1);
    alias_type s10(s2);
    shared_type s11(std::move(s1));
    alias_type s12(std::move(s2));

    // weak constructors
    typename shared_type::weak_type sw1(s6);
    alias_type s13(sw1);
    shared_type s14(sw1);
    EXPECT_EQ(*s13, *s6);
    EXPECT_EQ(sw1.use_count(), 3);
    EXPECT_EQ(s13.use_count(), 3);

    // unique_ptr constructors
    std::unique_ptr<type> u(new type(4));
    EXPECT_TRUE(u);
    shared_type s15(std::move(u));
    EXPECT_FALSE(u);
    EXPECT_EQ(*s15, 4);
}


template <typename T, bool ThreadSafe>
static
void
test_assignment()
{
    using type = T;
    using const_type = typename std::add_const<T>::type;
    using shared_type = shared_ptr<type, ThreadSafe>;
    using alias_type = shared_ptr<const_type, ThreadSafe>;

    // shared_ptr assignments
    shared_type s1;
    alias_type a1, a2;
    a2 = s1;
    a2 = a1;
    a2 = std::move(s1);
    a2 = std::move(a1);

    // unique_ptr assignments
    std::unique_ptr<type> u(new type(4));
    EXPECT_TRUE(u);
    s1 = std::move(u);
    EXPECT_FALSE(u);
    EXPECT_EQ(*s1, 4);
}


template <typename T, bool ThreadSafe>
static
void
test_observers()
{
    using type = T;
    using shared_type = shared_ptr<type, ThreadSafe>;

    // don't delete, just used to check `get()`
    type* p = new type(6);

    // 1 reference
    shared_type s1(p);
    EXPECT_EQ(s1.get(), p);
    EXPECT_EQ(s1.use_count(), 1);
    EXPECT_TRUE(s1.unique());
    EXPECT_TRUE(s1);
    EXPECT_FALSE(s1.owner_before(s1));

    // 2 references
    shared_type s2(s1);
    EXPECT_EQ(s1.get(), p);
    EXPECT_EQ(s2.get(), p);
    EXPECT_EQ(s1.use_count(), 2);
    EXPECT_EQ(s2.use_count(), 2);
    EXPECT_FALSE(s1.unique());
    EXPECT_FALSE(s2.unique());
    EXPECT_TRUE(s1);
    EXPECT_TRUE(s2);
    EXPECT_FALSE(s1.owner_before(s2));
    EXPECT_FALSE(s2.owner_before(s1));

    // 2 references, 1 invalid
    shared_type s3(std::move(s1));
    EXPECT_EQ(s1.get(), nullptr);
    EXPECT_EQ(s2.get(), p);
    EXPECT_EQ(s3.get(), p);
    EXPECT_EQ(s1.use_count(), 0);
    EXPECT_EQ(s2.use_count(), 2);
    EXPECT_EQ(s3.use_count(), 2);
    EXPECT_FALSE(s1.unique());
    EXPECT_FALSE(s2.unique());
    EXPECT_FALSE(s3.unique());
    EXPECT_FALSE(s1);
    EXPECT_TRUE(s2);
    EXPECT_TRUE(s3);
    EXPECT_TRUE(s1.owner_before(s2));
    EXPECT_FALSE(s2.owner_before(s1));

    // 1 reference, 2 invalid
    s3.reset();
    EXPECT_EQ(s1.get(), nullptr);
    EXPECT_EQ(s2.get(), p);
    EXPECT_EQ(s3.get(), nullptr);
    EXPECT_EQ(s1.use_count(), 0);
    EXPECT_EQ(s2.use_count(), 1);
    EXPECT_EQ(s3.use_count(), 0);
    EXPECT_FALSE(s1.unique());
    EXPECT_TRUE(s2.unique());
    EXPECT_FALSE(s3.unique());
    EXPECT_FALSE(s1);
    EXPECT_TRUE(s2);
    EXPECT_FALSE(s3);
    EXPECT_TRUE(s1.owner_before(s2));
    EXPECT_TRUE(s3.owner_before(s2));
    EXPECT_FALSE(s2.owner_before(s1));
    EXPECT_FALSE(s2.owner_before(s3));

    // test the remaining operators
    constexpr size_t size = 5;
    shared_type s4(new int[size]);
    for (size_t i = 0; i < size; ++i) {
        s4[i] = static_cast<int>(2*i);
    }
    EXPECT_EQ(s4[1], 2);
    EXPECT_EQ(*s4, 0);
    EXPECT_EQ(*(s4.operator->()), 0);
}


template <typename T, bool ThreadSafe>
static
void
test_modifiers()
{
    using type = T;
    using shared_type = shared_ptr<type, ThreadSafe>;
    using deleter_type = std::default_delete<type>;
    using allocator_type = std::allocator<type>;

    shared_type s1(new int(2));
    EXPECT_TRUE(s1);
    EXPECT_EQ(*s1, 2);

    // reset 0-args
    s1.reset();
    EXPECT_FALSE(s1);

    // reset 1-arg
    s1.reset(new int(3));
    EXPECT_TRUE(s1);
    EXPECT_EQ(*s1, 3);

    // reset 2-args
    s1.reset(new int(4), deleter_type());
    EXPECT_TRUE(s1);
    EXPECT_EQ(*s1, 4);

    // reset 3-args
    s1.reset(new int(5), deleter_type(), allocator_type());
    EXPECT_TRUE(s1);
    EXPECT_EQ(*s1, 5);

    // swap
    shared_type s2;
    EXPECT_TRUE(s1);
    EXPECT_FALSE(s2);
    EXPECT_EQ(*s1, 5);
    s1.swap(s2);
    EXPECT_TRUE(s2);
    EXPECT_FALSE(s1);
    EXPECT_EQ(*s2, 5);
}

template <bool ThreadSafe>
static
void
test_shared_from_this()
{
    using shared_type = shared<ThreadSafe>;
    auto s1 = make_shared<shared_type, ThreadSafe>();
    EXPECT_EQ(s1.use_count(), 1);
    auto s2 = s1->create();
    EXPECT_EQ(s1.use_count(), 2);
    EXPECT_EQ(s2.use_count(), 2);
    EXPECT_EQ(s1.get(), s2.get());
}


template <bool ThreadSafe>
static
void
test_make_shared()
{
    auto p1 = make_shared<int>(5);
    auto p2 = make_shared<int, ThreadSafe>(5);
    EXPECT_EQ(*p1, *p2);
}


template <bool ThreadSafe>
static
void
test_make_shared_array()
{
    // TODO: need to test all 4 constructors of make_shared...
}


template <bool ThreadSafe>
static
void
test_allocate_shared()
{
    using allocator_type = allocator<int>;
    allocator_type alloc;
    // ADL is a pain, sometimes...
    auto p1 = PYCPP_NAMESPACE::allocate_shared<int>(alloc, 5);
    auto p2 = allocate_shared<int, ThreadSafe>(alloc, 5);
    EXPECT_EQ(*p1, *p2);
}


template <bool ThreadSafe>
static
void
test_allocate_shared_array()
{
    // TODO: need to test all 3 constructors of allocate_shared...
}

// TESTS
// -----

TEST(shared_ptr, constructors)
{
    test_constructors<int, true>();
    test_constructors<int, false>();
}

TEST(shared_ptr, assignment)
{
    test_assignment<int, true>();
    test_assignment<int, false>();
}

TEST(shared_ptr, observers)
{
    test_observers<int, true>();
    test_observers<int, false>();
}

TEST(shared_ptr, modifiers)
{
    test_modifiers<int, true>();
    test_modifiers<int, false>();
}

TEST(shared_ptr, enable_shared_from_this)
{
    test_shared_from_this<true>();
    test_shared_from_this<false>();
}


TEST(shared_ptr, make_shared)
{
    test_make_shared<true>();
    test_make_shared<false>();
}


TEST(shared_ptr, make_shared_array)
{
    test_make_shared_array<true>();
    test_make_shared_array<false>();
}


TEST(shared_ptr, allocate_shared)
{
    test_allocate_shared<true>();
    test_allocate_shared<false>();
}


TEST(shared_ptr, allocate_shared_array)
{
    test_allocate_shared_array<true>();
    test_allocate_shared_array<false>();
}
