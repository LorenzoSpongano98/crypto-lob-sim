add_library(tf_feed src/json.cpp src/tls.cpp)
add_library(tf::feed ALIAS tf_feed)
target_include_directories(tf_feed PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(tf_feed
  PUBLIC tf::core
  PRIVATE simdjson::simdjson Boost::headers OpenSSL::SSL OpenSSL::Crypto Threads::Threads)
tf_configure_target(tf_feed)
