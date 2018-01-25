//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Launder unittests.
 */

#include <pycpp/stl/new/launder.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct data
{
    const int x;
    int y;
};

// TESTS
// -----

TEST(new_module, launder)
{
    // launder the pointer so we can reinitialize a buffer through
    // const-ness. When we use placement new on an initialized object,
    // we don't get a pointer to the correct buffer, UB.
    // Using `launder` allows us guarantees.
    data d = {1, 2};
    data* p = &d;
    new (p) data {7, 8};
    p = launder(p);
    EXPECT_EQ(p->x, 7);
}
