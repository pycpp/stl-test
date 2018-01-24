//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `cend` unittests.
 */

#include <pycpp/stl/iterator/cend.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(iterator, cend)
{
    int x[5];
    auto it = cend(x);
}
