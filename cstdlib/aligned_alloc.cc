//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `aligned_alloc` unittests.
 */

#include <pycpp/stl/cstdlib/aligned_alloc.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TEST
// ----

TEST(cstdlib, aligned_alloc)
{
    void* p = aligned_alloc(alignof(int), sizeof(int) * 10);
    ASSERT_NE(p, nullptr);
    aligned_free(p);
}
