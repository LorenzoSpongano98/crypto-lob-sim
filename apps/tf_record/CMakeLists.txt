add_executable(tf_record_app main.cpp)
set_target_properties(tf_record_app PROPERTIES OUTPUT_NAME tf-record)
target_link_libraries(tf_record_app PRIVATE tf::core tf::feed tf::record quill::quill)
tf_configure_target(tf_record_app)
