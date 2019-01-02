cmake_minimum_required(VERSION 3.12)
PROJECT(khala)

SET(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(include)

SET(khala_base_files src/base/event_loop.cc
                     include/khala/base/macro_helper.hh
                     include/khala/serializer/binary.hh)

SET(khala_serializer_files src/serializer/json.cc
                           src/serializer/binary.cc)

ADD_LIBRARY(khala_base ${khala_base_files})
ADD_LIBRARY(khala_serializer ${khala_serializer_files})

SET(khala_base_test_files test/base/event_queue_test.cc
                          test/base/reflection_test.cc
                          test/base/utility_test.cc
                          test/base/buffer_test.cc)

SET(khala_serializer_test_files test/serializer/json_serializer_test.cc test/serializer/binary_serializer_test.cc)

ADD_EXECUTABLE(khala_test ${khala_base_test_files}
        ${khala_serializer_test_files})

FIND_LIBRARY(LIBUV libuv.a)
      
SET_TARGET_PROPERTIES(khala_test PROPERTIES LINK_SEARCH_START_STATIC 1)

TARGET_LINK_LIBRARIES(khala_test gtest_main ${LIBUV} gtest glog gflags
        khala_base khala_serializer)

SET_TARGET_PROPERTIES(khala_test PROPERTIES LINK_SEARCH_END_STATIC 1)

TARGET_LINK_LIBRARIES(khala_test pthread)

