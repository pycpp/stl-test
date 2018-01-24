//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_iterator` unittests.
 */

#include <pycpp/stl/type_traits/is_iterator.h>
#include <gtest/gtest.h>
#include <iterator>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct input_iterator: std::iterator<std::input_iterator_tag, int>
{};

struct output_iterator: std::iterator<std::output_iterator_tag, int>
{};

struct forward_iterator: std::iterator<std::forward_iterator_tag, int>
{};

struct bidirectional_iterator: std::iterator<std::bidirectional_iterator_tag, int>
{};

struct random_access_iterator: std::iterator<std::random_access_iterator_tag, int>
{};

// TESTS
// -----

TEST(is_iterator, is_iterator)
{
    static_assert(is_input_iterator<input_iterator>::value, "");
    static_assert(!is_input_iterator<output_iterator>::value, "");
    static_assert(!is_input_iterator<forward_iterator>::value, "");
    static_assert(!is_input_iterator<bidirectional_iterator>::value, "");
    static_assert(!is_input_iterator<random_access_iterator>::value, "");
    static_assert(!is_output_iterator<input_iterator>::value, "");
    static_assert(is_output_iterator<output_iterator>::value, "");
    static_assert(!is_output_iterator<forward_iterator>::value, "");
    static_assert(!is_output_iterator<bidirectional_iterator>::value, "");
    static_assert(!is_output_iterator<random_access_iterator>::value, "");
    static_assert(!is_forward_iterator<input_iterator>::value, "");
    static_assert(!is_forward_iterator<output_iterator>::value, "");
    static_assert(is_forward_iterator<forward_iterator>::value, "");
    static_assert(!is_forward_iterator<bidirectional_iterator>::value, "");
    static_assert(!is_forward_iterator<random_access_iterator>::value, "");
    static_assert(!is_bidirectional_iterator<input_iterator>::value, "");
    static_assert(!is_bidirectional_iterator<output_iterator>::value, "");
    static_assert(!is_bidirectional_iterator<forward_iterator>::value, "");
    static_assert(is_bidirectional_iterator<bidirectional_iterator>::value, "");
    static_assert(!is_bidirectional_iterator<random_access_iterator>::value, "");
    static_assert(!is_random_access_iterator<input_iterator>::value, "");
    static_assert(!is_random_access_iterator<output_iterator>::value, "");
    static_assert(!is_random_access_iterator<forward_iterator>::value, "");
    static_assert(!is_random_access_iterator<bidirectional_iterator>::value, "");
    static_assert(is_random_access_iterator<random_access_iterator>::value, "");

    // concepts
    static_assert(is_input_iterable<input_iterator>::value, "");
    static_assert(!is_input_iterable<output_iterator>::value, "");
    static_assert(is_input_iterable<forward_iterator>::value, "");
    static_assert(is_input_iterable<bidirectional_iterator>::value, "");
    static_assert(is_input_iterable<random_access_iterator>::value, "");
    static_assert(!is_output_iterable<input_iterator>::value, "");
    static_assert(is_output_iterable<output_iterator>::value, "");
    static_assert(!is_output_iterable<forward_iterator>::value, "");
    static_assert(!is_output_iterable<bidirectional_iterator>::value, "");
    static_assert(!is_output_iterable<random_access_iterator>::value, "");
    static_assert(!is_forward_iterable<input_iterator>::value, "");
    static_assert(!is_forward_iterable<output_iterator>::value, "");
    static_assert(is_forward_iterable<forward_iterator>::value, "");
    static_assert(is_forward_iterable<bidirectional_iterator>::value, "");
    static_assert(is_forward_iterable<random_access_iterator>::value, "");
    static_assert(!is_bidirectional_iterable<input_iterator>::value, "");
    static_assert(!is_bidirectional_iterable<output_iterator>::value, "");
    static_assert(!is_bidirectional_iterable<forward_iterator>::value, "");
    static_assert(is_bidirectional_iterable<bidirectional_iterator>::value, "");
    static_assert(is_bidirectional_iterable<random_access_iterator>::value, "");
    static_assert(!is_random_access_iterable<input_iterator>::value, "");
    static_assert(!is_random_access_iterable<output_iterator>::value, "");
    static_assert(!is_random_access_iterable<forward_iterator>::value, "");
    static_assert(!is_random_access_iterable<bidirectional_iterator>::value, "");
    static_assert(is_random_access_iterable<random_access_iterator>::value, "");
}
