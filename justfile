default:
    @just --list

check: fmt-check (test "asan")

test preset="debug":
    cmake --preset {{preset}}
    cmake --build --preset {{preset}}
    ctest --preset {{preset}}

build preset="debug":
    cmake --preset {{preset}}
    cmake --build --preset {{preset}}

tidy:
    cmake --preset tidy
    cmake --build --preset tidy

fmt:
    git ls-files '*.cpp' '*.hpp' | xargs clang-format -i

fmt-check:
    git ls-files '*.cpp' '*.hpp' | xargs clang-format --dry-run --Werror

bench *args: (build "release")
    ./build/release/bench/tf_bench {{args}}

lsp: (build "debug")
    ln -sf build/debug/compile_commands.json compile_commands.json

clean:
    rm -rf build
