//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Endian enumeration unittests.
 */

#include <pycpp/stl/type_traits/endian.h>
#include <gtest/gtest.h>
#include <type_traits>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(endian, endian)
{
    static_assert(std::is_enum<endian>::value, "");
    endian little = endian::little;
    endian big = endian::big;
    endian native = endian::native;

    EXPECT_NE(little, big);
#if BYTE_ORDER == LITTLE_ENDIAN     // LITTLE_ENDIAN
    EXPECT_EQ(little, native);
#else                               // BIG_ENDIAN
    EXPECT_EQ(big, native);
#endif                              // LITTLE_ENDIAN
}
