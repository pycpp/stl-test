//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief <execution> unittests.
 */

#include <pycpp/preprocessor/compiler_traits.h>
// TODO(ahuszagh): Wish list.
// None of the STL implements have implemented the parallel execution
// algorithms.
// Change when they become available.
#if defined(HAVE_CPP17)
#   if PYCPP_HAS_INCLUDE(<execution>)
#       include <pycpp/stl/execution.h>
#   endif
#endif
#include <gtest/gtest.h>
