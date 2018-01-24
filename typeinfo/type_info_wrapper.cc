//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Type info wrapper unittests.
 */

#include <pycpp/stl/typeinfo/type_info_wrapper.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(type_info_wrapper, constructors)
{
    type_info_wrapper t1;
    type_info_wrapper t2(t1);
    type_info_wrapper t3(std::move(t2));
    type_info_wrapper t4(typeid(int));
}

TEST(type_info_wrapper, assignment)
{
    type_info_wrapper t1;
    type_info_wrapper t2;
    t1 = t2;
    t1 = std::move(t2);
    t1 = typeid(int);
}

TEST(type_info_wrapper, observers)
{
    type_info_wrapper t1;
    type_info_wrapper t2 = typeid(int);
    EXPECT_FALSE(t1);
    EXPECT_TRUE(t2);
    EXPECT_TRUE(!t1);
    EXPECT_FALSE(!t2);

    const std::type_info& i = *t2;
    const char* name = t2->name();
    EXPECT_EQ(i, typeid(int));

    EXPECT_TRUE(t1.empty());
    EXPECT_FALSE(t2.empty());
    EXPECT_NE(t1.pretty_name(), t2.pretty_name());
}

TEST(type_info_wrapper, modifiers)
{
    type_info_wrapper t1;
    type_info_wrapper t2 = typeid(int);

    EXPECT_FALSE(t1);
    EXPECT_TRUE(t2);

    t1.swap(t2);
    EXPECT_FALSE(t2);
    EXPECT_TRUE(t1);

    swap(t1, t2);
    EXPECT_FALSE(t1);
    EXPECT_TRUE(t2);
}

TEST(type_info_wrapper, relative_operators)
{
    // null initialized is **always** < typeid()
    type_info_wrapper t1;
    type_info_wrapper t2 = typeid(int);

    EXPECT_EQ(t1, t1);
    EXPECT_EQ(t2, t2);
    EXPECT_NE(t1, t2);
    EXPECT_NE(t2, t1);
    EXPECT_LT(t1, t2);
    EXPECT_LE(t1, t2);
    EXPECT_GT(t2, t1);
    EXPECT_GE(t2, t1);
}
