#include <gtest/gtest.h>

#include <cstdint>
#include <optional>

#include "tf/feed/json.hpp"
#include "tf/feed/tls.hpp"

TEST(Feed, ReadsAnUnsignedField) {
    const auto id =
        tf::feed::read_u64_field(R"({"lastUpdateId": 160, "bids": []})", "lastUpdateId");
    EXPECT_EQ(id, std::optional<std::uint64_t>{160});
}

TEST(Feed, MissingFieldOrBadJsonGivesNothing) {
    EXPECT_FALSE(tf::feed::read_u64_field(R"({"a": 1})", "b").has_value());
    EXPECT_FALSE(tf::feed::read_u64_field("{not json", "a").has_value());
}

TEST(Feed, TlsClientContextBuilds) {
    EXPECT_TRUE(tf::feed::tls_client_context_ok());
}
