//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `integer_sequence` backport unittests.
 */

#include <pycpp/stl/utility/integer_sequence.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(utility, integer_sequence)
{
    using seq1 = integer_sequence<int, 0, 1>;
    static_assert(seq1::size() == 2, "");

    using seq2 = index_sequence<0, 1, 2>;
    static_assert(seq2::size() == 3, "");

    using seq3 = make_integer_sequence<int, 4>;
    static_assert(seq3::size() == 4, "");

    using seq4 = make_index_sequence<5>;
    static_assert(seq4::size() == 5, "");

    using seq5 = index_sequence_for<int, float, char, unsigned>;
    static_assert(seq5::size() == 4, "");
}
