add_executable(tf_bench feed_bench.cpp)
target_link_libraries(tf_bench PRIVATE tf::feed benchmark::benchmark_main)
tf_configure_target(tf_bench)
