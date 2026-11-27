# 3. FetchContent for small libraries, Boost and OpenSSL from the system

Status: Accepted
Date: 2026-11-27

## Context
The project needs Boost.Asio and Boost.Beast (header-only), OpenSSL, simdjson, Quill,
GoogleTest and Google Benchmark. Options: vcpkg, Conan, system packages, CMake FetchContent.

## Decision
- simdjson, Quill, GoogleTest and Google Benchmark: `FetchContent`, pinned to a tag in
  `cmake/Dependencies.cmake`, with `FIND_PACKAGE_ARGS` so an installed package wins.
- Boost and OpenSSL: from the system (Ubuntu 24.04 ships Boost 1.83 with Beast; Arch ships newer).

## Consequences
- No package manager to learn or cache in CI; a cold configure takes about 15 seconds.
- Versions are bumped by hand, since Dependabot cannot see FetchContent pins.
- If the dependency list grows (for example Arrow or Parquet in C++), revisit with vcpkg in manifest mode.
