#include <gtest/gtest.h>

#include <type_traits>

#include "tf/core/types.hpp"
#include "tf/core/version.hpp"

TEST(Core, StrongTypesCompareAndDoNotMix) {
    const tf::Price low{100};
    const tf::Price high{101};
    EXPECT_LT(low, high);
    EXPECT_EQ(high.value(), 101);
    static_assert(!std::is_convertible_v<tf::Price, tf::Qty>);
    static_assert(!std::is_convertible_v<tf::Price::rep, tf::Price>);
}

TEST(Core, VersionIsSet) {
    EXPECT_FALSE(tf::version().empty());
}
