//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_final` unittests.
 */

#include <pycpp/stl/type_traits/is_final.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct base
{
    virtual void call();
};

struct derived final: base
{
    void call() final;
};

// TESTS
// -----

TEST(is_final, is_final)
{
    static_assert(!is_final<int>::value, "");
    static_assert(!is_final<base>::value, "");
#ifdef HAVE_CPP14
    static_assert(!is_final_v<int>, "");
    static_assert(!is_final_v<base>, "");
#endif

#ifdef PYCPP_IS_FINAL
    static_assert(is_final<derived>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_final_v<derived>, "");
#endif  // HAVE_CPP14
#endif  // PYCPP_IS_FINAL
}
