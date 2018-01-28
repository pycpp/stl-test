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
    constexpr size_t alignment = alignof(int);
    void* p = aligned_alloc(alignment, sizeof(int) * 10);
    ASSERT_NE(p, nullptr);
    aligned_free(p);
}


TEST(cstdlib, aligned_realloc)
{
    // check initial with null
    constexpr size_t alignment = alignof(int);
    constexpr size_t old_size = sizeof(int) * 10;
    constexpr size_t new_size = sizeof(int) * 20;
    void* p = aligned_realloc(nullptr, alignment, 0, old_size);
    ASSERT_NE(p, nullptr);
    p = aligned_realloc(p, alignment, old_size, new_size);
    aligned_free(p);
}
