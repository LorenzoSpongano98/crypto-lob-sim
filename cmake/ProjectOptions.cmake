set(TF_GCC_CLANG_WARNINGS
  -Wall -Wextra -Wpedantic
  -Wshadow -Wconversion -Wsign-conversion
  -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual
  -Wcast-align -Wnull-dereference -Wdouble-promotion
  -Wformat=2 -Wimplicit-fallthrough)

if(TF_CLANG_TIDY)
  find_program(TF_CLANG_TIDY_EXE NAMES clang-tidy clang-tidy-18 REQUIRED)
endif()

function(tf_configure_target target)
  target_compile_options(${target} PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:${TF_GCC_CLANG_WARNINGS}>
    $<$<AND:$<CXX_COMPILER_ID:GNU,Clang>,$<BOOL:${TF_WARNINGS_AS_ERRORS}>>:-Werror>)

  if(TF_SANITIZE)
    list(JOIN TF_SANITIZE "," _tf_sanitizers)
    target_compile_options(${target} PRIVATE
      -fsanitize=${_tf_sanitizers} -fno-omit-frame-pointer -fno-sanitize-recover=all)
    target_link_options(${target} PRIVATE -fsanitize=${_tf_sanitizers})
  endif()

  if(TF_CLANG_TIDY)
    set_target_properties(${target} PROPERTIES CXX_CLANG_TIDY "${TF_CLANG_TIDY_EXE}")
  endif()
endfunction()
