//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief <forward_list> unittests.
 */

#include <pycpp/stl/forward_list.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE


// TESTS
// -----

// FORWARD LIST FACET

TEST(forward_list_facet, element_access)
{
    forward_list<int> l = {1};
    auto& facet = l.facet();
    const auto& cfacet = l.facet();

    EXPECT_EQ(cfacet.front(), 1);
    facet.front() = 3;
    EXPECT_EQ(cfacet.front(), 3);
}


TEST(forward_list_facet, iterators)
{
    // TODO:
}


TEST(forward_list_facet, capacity)
{
    // TODO:
}

// FORWARD LIST


TEST(forward_list, element_access)
{
    // TODO:
}


TEST(forward_list, iterators)
{
    // TODO:
}


TEST(forward_list, capacity)
{
    // TODO:
}
