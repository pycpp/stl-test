//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief <cuchar> unittests.
 */

#include <pycpp/preprocessor/compiler_traits.h>
#if !defined(PYCPP_CLANG) || PYCPP_HAS_INCLUDE(<cuchar>)
// libc++ doesn't necessarily contain cuchar
#   include <pycpp/stl/cuchar.h>
#endif
#include <gtest/gtest.h>
