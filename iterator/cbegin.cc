//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `cbegin` unittests.
 */

#include <pycpp/stl/iterator/cbegin.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(iterator, cbegin)
{
    int x[5];
    auto it = cbegin(x);
}
