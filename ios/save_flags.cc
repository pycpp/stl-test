//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `save_flags` unittests.
 */

#include <pycpp/stl/ios/save_flags.h>
#include <gtest/gtest.h>
#include <sstream>

PYCPP_USING_NAMESPACE

// TESTS
// -----


TEST(save_flags, save_flags)
{
    using char_type = typename std::stringstream::char_type;
    using traits_type = typename std::stringstream::traits_type;

    std::stringstream stream;
    auto flags = stream.flags();
    auto fill = stream.fill();

    {
        save_flags<char_type, traits_type> sf(stream);
        stream << std::hex;
        stream << std::setfill('*');
        EXPECT_NE(stream.flags(), flags);
        EXPECT_NE(stream.fill(), fill);
    }

    EXPECT_EQ(stream.flags(), flags);
    EXPECT_EQ(stream.fill(), fill);
}
