//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief intrusive_ptr unittests.
 */

#include <pycpp/stl/memory/intrusive_ptr.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct intref
{
    int x;
    unsigned c;

    intref(int a):
        x(a),
        c(0)
    {}
};

template <typename T>
struct intrusive_count
{
    static void
    add_ref(
        T* p
    )
    {
        ++p->c;
    }

    static void
    release(
        T* p
    )
    {
        if (--p->c == 0) {
            delete p;
        }
    }
};

// TESTS
// -----

TEST(intrusive_ptr, intrusive_ptr)
{
    using ptr_type = intrusive_ptr<intref, intrusive_count<intref>>;
    ptr_type p1;
    ptr_type p2(new intref(5), true);
    EXPECT_EQ(p2->x, 5);

    // no manual ref added
    intref* p = new intref(5);
    {
        ptr_type p3(p, false);
        EXPECT_EQ(p3->c, 0);
        ++p3->c;
    }
    EXPECT_EQ(p->c, 0);

    // copy
    EXPECT_EQ(p2->c, 1);
    ptr_type p4(p2);
    EXPECT_EQ(p2->x, 5);
    EXPECT_EQ(p2->c, 2);
    EXPECT_EQ(p4->c, 2);
    EXPECT_EQ(p2.get(), p4.get());

    p4.reset();
    EXPECT_EQ(p2->c, 1);
    EXPECT_EQ(p4.get(), nullptr);

    // move
    ptr_type p5(std::move(p2));
    EXPECT_EQ(p5->x, 5);
    EXPECT_EQ(p5->c, 1);
    EXPECT_EQ(p2.get(), nullptr);

    // observers
    EXPECT_TRUE(p5);
    EXPECT_FALSE(p2);
    intref& ri = *p5;
    int& rx = p5->x;
}
