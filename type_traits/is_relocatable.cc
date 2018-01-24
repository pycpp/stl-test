//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief `is_relocatable` unittests.
 */

#include <pycpp/stl/type_traits/is_relocatable.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// DATA
// ----

struct empty
{};

struct pod_struct
{
    int x;
    int y;
};

struct virtual_struct
{
    virtual ~virtual_struct();
};

// TESTS
// -----

TEST(is_relocatable, is_relocatable)
{
    static_assert(is_relocatable<int>::value, "");
    static_assert(is_relocatable<int[5]>::value, "");
    static_assert(is_relocatable<empty>::value, "");
    static_assert(is_relocatable<pod_struct>::value, "");
    static_assert(!is_relocatable<virtual_struct>::value, "");
#ifdef HAVE_CPP14
    static_assert(is_relocatable_v<int>, "");
    static_assert(is_relocatable_v<int[5]>, "");
    static_assert(is_relocatable_v<empty>, "");
    static_assert(is_relocatable_v<pod_struct>, "");
    static_assert(!is_relocatable_v<virtual_struct>, "");
#endif
}


TEST(is_relocatable, enable_relocatable)
{
    using t1 = typename enable_relocatable<pod_struct>::type;
    using t2 = enable_relocatable_t<pod_struct>;
    static_assert(std::is_same<t1, t2>::value, "");
}
