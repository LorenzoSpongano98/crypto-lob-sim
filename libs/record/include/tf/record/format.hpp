#pragma once

#include <array>
#include <cstdint>
#include <span>

namespace tf::record {

struct FileHeader {
    std::array<char, 4> magic{'T', 'F', 'R', 'C'};
    std::uint16_t version{1};
    std::uint16_t reserved{0};
};

[[nodiscard]] bool is_valid(const FileHeader& header) noexcept;

[[nodiscard]] bool parse_header(std::span<const std::byte> bytes, FileHeader& out) noexcept;

}
