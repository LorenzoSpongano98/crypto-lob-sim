#include "tf/feed/json.hpp"

#include <simdjson.h>

namespace tf::feed {

std::optional<std::uint64_t> read_u64_field(std::string_view json, std::string_view key) {
    simdjson::ondemand::parser parser;
    const simdjson::padded_string padded{json};
    simdjson::ondemand::document doc;
    if (parser.iterate(padded).get(doc) != simdjson::SUCCESS) {
        return std::nullopt;
    }
    std::uint64_t value{};
    if (doc[key].get_uint64().get(value) != simdjson::SUCCESS) {
        return std::nullopt;
    }
    return value;
}

}
