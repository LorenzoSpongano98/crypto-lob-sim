# 2. Use C++23 instead of Rust

Status: Accepted
Date: 2026-11-27

## Context
The project started as a Rust workspace (`tf-core`, `tf-feed`, `tf-record`, `tf-bin`).
I am more productive in C++, Rust would have delayed the feed handler by several weeks of
language study, and low-latency trading roles ask for C++ far more often than for Rust.

## Decision
Rewrite the skeleton in C++23 with CMake, keeping the same split into libraries
(`tf_core`, `tf_feed`, `tf_record`) and executables. The last Rust state is tagged `rust-archive`.

## Consequences
- The feed handler starts immediately.
- Memory and thread safety rely on discipline plus ASan, UBSan, TSan and clang-tidy in CI.
- Rust comes back later as a measured comparison: one component (the order book or the SPSC queue)
  rewritten in Rust with the same tests and benchmarks.
