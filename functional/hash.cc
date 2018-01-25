//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Customized hash function unittests.
 */

#include <pycpp/stl/functional/hash.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

enum class enumerated
{
    first = 0,
    second = 1,
};

// TESTS
// -----

TEST(functional, hash)
{
    EXPECT_NE(hash<bool>()(false), -1);
    EXPECT_NE(hash<char>()('a'), -1);
    EXPECT_NE(hash<unsigned char>()('a'), -1);
    EXPECT_NE(hash<char16_t>()(0), -1);
    EXPECT_NE(hash<char32_t>()(0), -1);
    EXPECT_NE(hash<wchar_t>()(0), -1);
    EXPECT_NE(hash<short>()(0), -1);
    EXPECT_NE(hash<unsigned short>()(0), -1);
    EXPECT_NE(hash<int>()(0), -1);
    EXPECT_NE(hash<unsigned int>()(0), -1);
    EXPECT_NE(hash<long>()(0), -1);
    EXPECT_NE(hash<long long>()(0), -1);
    EXPECT_NE(hash<unsigned long>()(0), -1);
    EXPECT_NE(hash<unsigned long long>()(0), -1);
    EXPECT_NE(hash<float>()(0.1), -1);
    EXPECT_NE(hash<double>()(0.2), -1);
    EXPECT_NE(hash<long double>()(0.2), -1);
    EXPECT_NE(hash<std::nullptr_t>()(nullptr), -1);
    EXPECT_NE(hash<void*>()(nullptr), -1);
    EXPECT_NE(hash<char*>()(nullptr), -1);
    EXPECT_NE(hash<enumerated>()(enumerated::first), -1);
}
