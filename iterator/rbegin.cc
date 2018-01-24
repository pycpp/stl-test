//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `rbegin` unittests.
 */

#include <pycpp/stl/iterator/rbegin.h>
#include <gtest/gtest.h>
#include <vector>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(iterator, rbegin)
{
    int x[5];
    std::initializer_list<int> il = {5};
    std::vector<int> v = {5};

    auto it1 = rbegin(x);
    auto it2 = rbegin(il);
    auto it3 = rbegin(v);
    auto it4 = crbegin(v);
}
