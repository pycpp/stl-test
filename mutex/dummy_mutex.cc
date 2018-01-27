//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Dummy mutex unittests.
 */

#include <pycpp/stl/mutex/dummy_mutex.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// TESTS
// -----

TEST(mutex, dummy_mutex)
{
    dummy_mutex mu;
    mu.lock();
    mu.unlock();
    EXPECT_TRUE(mu.try_lock());
    EXPECT_EQ(mu.native_handle(), nullptr);
}
