#pragma once

#include <compare>
#include <cstdint>

namespace tf {

template <typename Tag>
class Strong {
public:
    using rep = std::int64_t;

    constexpr Strong() noexcept = default;
    constexpr explicit Strong(rep value) noexcept : value_{value} {}

    [[nodiscard]] constexpr rep value() const noexcept { return value_; }

    constexpr auto operator<=>(const Strong&) const noexcept = default;

private:
    rep value_{0};
};

using Price = Strong<struct PriceTag>;
using Qty = Strong<struct QtyTag>;

using SeqNo = std::uint64_t;
using Nanos = std::int64_t;

enum class Side : std::uint8_t { Bid, Ask };

}
