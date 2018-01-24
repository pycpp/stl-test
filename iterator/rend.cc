//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `rend` unittests.
 */

#include <pycpp/stl/iterator/rend.h>
#include <gtest/gtest.h>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(iterator, rend)
{
    int x[5];
    std::initializer_list<int> il = {5};
    std::vector<int> v = {5};

    auto it1 = rend(x);
    auto it2 = rend(il);
    auto it3 = rend(v);
    auto it4 = crend(v);
}
