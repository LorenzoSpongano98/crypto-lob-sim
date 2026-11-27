include(GoogleTest)

add_executable(tf_tests core_test.cpp record_test.cpp feed_test.cpp)
target_link_libraries(tf_tests PRIVATE tf::core tf::record tf::feed GTest::gtest_main)
tf_configure_target(tf_tests)
gtest_discover_tests(tf_tests DISCOVERY_MODE PRE_TEST)
