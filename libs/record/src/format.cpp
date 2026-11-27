#include "tf/record/format.hpp"

#include <cstring>
#include <type_traits>

namespace tf::record {

static_assert(std::is_trivially_copyable_v<FileHeader>);
static_assert(sizeof(FileHeader) == 8);

bool is_valid(const FileHeader& header) noexcept {
    constexpr FileHeader expected{};
    return header.magic == expected.magic && header.version == expected.version;
}

bool parse_header(std::span<const std::byte> bytes, FileHeader& out) noexcept {
    if (bytes.size() < sizeof(FileHeader)) {
        return false;
    }
    std::memcpy(&out, bytes.data(), sizeof(FileHeader));
    return is_valid(out);
}

}
