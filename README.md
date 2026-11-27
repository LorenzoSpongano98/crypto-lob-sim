# tickforge

A C++23 platform for crypto markets:

1. **Feed handler**: records exchange order books without losing a message (m1).
2. **Limit order book and matching engine**: price-time priority, no allocations on the hot path (m2).
3. **Market simulator**: network and exchange latency, queue position, partial fills (m3).
4. **Event-driven backtest engine**: deterministic, with Python bindings (m4).

Status: m1 in progress. Design notes are in [docs/design.md](docs/design.md), decisions in [docs/adr](docs/adr/).

## Build

Requirements: CMake 3.28+, Ninja, GCC 14+ or Clang 18+, Boost 1.83+ (headers only) and OpenSSL.
simdjson, Quill, GoogleTest and Google Benchmark are fetched at configure time, or taken from the system if installed.

```sh
# Arch / CachyOS
sudo pacman -S --needed cmake ninja boost openssl just clang
# Ubuntu 24.04
sudo apt install cmake ninja-build libboost-dev libssl-dev just clang

cmake --preset debug && cmake --build --preset debug && ctest --preset debug
```

| Preset | What it is for |
|---|---|
| `debug` | everyday development |
| `release` | benchmarks and `perf` (RelWithDebInfo) |
| `asan` | AddressSanitizer and UndefinedBehaviorSanitizer |
| `tsan` | ThreadSanitizer |
| `tidy` | clang-tidy on every source file |

With [just](https://github.com/casey/just): `just test asan`, `just bench`, `just tidy`, `just fmt`.
Enable the pre-push hook once per clone with `git config core.hooksPath .githooks`.

## Layout

```
libs/core     tf::core    strong types for prices, quantities, timestamps
libs/feed     tf::feed    WebSocket transport, decoders, book sync (m1)
libs/record   tf::record  append-only binary recording format (m1)
apps/         executables (tf-record)
tests/        GoogleTest
bench/        Google Benchmark
```

## License

MIT
