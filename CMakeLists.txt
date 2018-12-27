cmake_minimum_required(VERSION 3.12)
PROJECT(khala)

SET(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(include)

SET(khala_base_files src/base/event_loop.cc main.cpp include/khala/base/macro_helper.hh)
SET(khala_serializer_files src/serializer/json.cc)

ADD_LIBRARY(khala_base ${khala_base_files})
ADD_LIBRARY(khala_serializer ${khala_serializer_files})

SET(khala_base_test_files test/base/event_queue_test.cc
        test/base/reflection_test.cc)

SET(khala_serializer_test_files test/serializer/json_serializer_test.cc)

ADD_EXECUTABLE(khala_test ${khala_base_test_files}
        ${khala_serializer_test_files})
TARGET_LINK_LIBRARIES(khala_test gtest_main gtest uv glog gflags
        khala_base
        khala_serializer)