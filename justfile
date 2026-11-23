check:
  cargo fmt --all --check
  cargo clippy --workspace --all-targets --all-features --locked -- -D warnings
  cargo test --workspace --all-targets --all-features --locked 
  cargo test --workspace --doc --all-targets --locked

fmt:
  cargo fmt --all 
