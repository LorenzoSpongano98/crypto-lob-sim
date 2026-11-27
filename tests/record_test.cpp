#include <gtest/gtest.h>

#include <array>
#include <cstddef>
#include <cstring>

#include "tf/record/format.hpp"

TEST(Record, HeaderRoundTrip) {
    const tf::record::FileHeader written{};
    std::array<std::byte, sizeof(tf::record::FileHeader)> bytes{};
    std::memcpy(bytes.data(), &written, sizeof written);

    tf::record::FileHeader read{};
    ASSERT_TRUE(tf::record::parse_header(bytes, read));
    EXPECT_TRUE(tf::record::is_valid(read));
}

TEST(Record, RejectsShortInputAndWrongMagic) {
    tf::record::FileHeader out{};
    std::array<std::byte, 3> few{};
    EXPECT_FALSE(tf::record::parse_header(few, out));

    tf::record::FileHeader wrong{};
    wrong.magic[0] = 'X';
    std::array<std::byte, sizeof wrong> bytes{};
    std::memcpy(bytes.data(), &wrong, sizeof wrong);
    EXPECT_FALSE(tf::record::parse_header(bytes, out));
}
