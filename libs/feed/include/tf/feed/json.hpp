#pragma once

#include <cstdint>
#include <optional>
#include <string_view>

namespace tf::feed {

[[nodiscard]] std::optional<std::uint64_t> read_u64_field(std::string_view json,
                                                          std::string_view key);

}
