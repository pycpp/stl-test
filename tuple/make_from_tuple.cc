//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `make_from_tuple` backport unittests.
 */

#include <pycpp/stl/tuple/make_from_tuple.h>
#include <gtest/gtest.h>
#include <string>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(tuple, make_from_tuple)
{
    const char* p = "This is a string";
    size_t len = 16;
    using tuple_type = std::tuple<const char*, size_t>;

    auto str = make_from_tuple<std::string>(tuple_type(p, len));
    EXPECT_EQ(str, std::string(p, len));
}
