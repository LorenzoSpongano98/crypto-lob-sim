#include <benchmark/benchmark.h>

#include <string_view>

#include "tf/feed/json.hpp"

namespace {

void BM_ReadU64Field(benchmark::State& state) {
    constexpr std::string_view msg = R"({"e":"depthUpdate","E":1700000000000,"U":157,"u":160})";
    for (auto _ : state) {
        benchmark::DoNotOptimize(tf::feed::read_u64_field(msg, "u"));
    }
}
BENCHMARK(BM_ReadU64Field);

}
