//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `make_reverse_iterator` unittests.
 */

#include <pycpp/stl/iterator/make_reverse_iterator.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(iterator, make_reverse_iterator)
{
    char* p = nullptr;
    auto it = make_reverse_iterator(p);
}
