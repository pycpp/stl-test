//  :copyright: (c) 2017-2018 Alex Huszagh.
//  :license: MIT, see LICENSE.md for more details.
/*
 *  \addtogroup Tests
 *  \brief Runtime thread-checking unittests.
 */

#include <pycpp/stl/thread/checked_thread.h>
#include <gtest/gtest.h>

PYCPP_USING_NAMESPACE

// HELPERS
// -------

template <bool ThreadSafe>
static
void
call_check(
    checked_thread<ThreadSafe>* checker
)
{
    checker->check();
}


template <typename Function, typename ... Ts>
static
void
new_joined_thread(
    Function f,
    Ts&&... ts
)
{
    std::thread thread(f, std::forward<Ts>(ts)...);
    thread.join();
}

// TESTS
// -----

TEST(checked_thread, thread_safe_true)
{
    using type = checked_thread<true>;

    type checker;
    new_joined_thread(call_check<true>, &checker);
}


TEST(checked_thread, thread_safe_false)
{
    using type = checked_thread<false>;

#ifndef NDEBUG
    type checker;

    auto call = [&checker]() -> void
    {
        new_joined_thread(call_check<false>, &checker);
    };

    // May produce a spurious GTest warning, ignore.
    //      Death tests use fork(), which is unsafe particularly in a
    //      threaded context.
    ASSERT_DEATH(call(), "");
#endif
}
