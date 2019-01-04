cmake_minimum_required(VERSION 3.12)
PROJECT(khala)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_C_STANDARD 11)

ADD_COMPILE_OPTIONS(-Wall -Werror)

INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(include/third_party)

SET(khala_base_files src/khala/base/event_loop.cc
                     include/khala/base/macro_helper.hh
                     include/khala/serializer/binary.hh)

SET(khala_serializer_files src/khala/serializer/json.cc
                           src/khala/serializer/binary.cc)

SET(khala_network_files src/khala/network/types.cc)

SET(khala_third_party_files src/third_party/ikcp.c
                            src/third_party/fmt/posix.cc
                            src/third_party/fmt/format.cc)

ADD_LIBRARY(khala_base ${khala_base_files})
ADD_LIBRARY(khala_serializer ${khala_serializer_files})
ADD_LIBRARY(khala_network ${khala_network_files})
ADD_LIBRARY(khala_third_party ${khala_third_party_files})

SET(khala_base_test_files test/base/event_queue_test.cc
                          test/base/reflection_test.cc
                          test/base/utility_test.cc
                          test/base/buffer_test.cc
                          test/base/emitter_test.cc
                          test/network/udp_socket_test.cc)

SET(khala_serializer_test_files test/serializer/json_serializer_test.cc test/serializer/binary_serializer_test.cc)

ADD_EXECUTABLE(khala_test ${khala_base_test_files}
        ${khala_serializer_test_files})

FIND_LIBRARY(LIBUV libuv.a)
      
SET_TARGET_PROPERTIES(khala_test PROPERTIES LINK_SEARCH_START_STATIC 1)

TARGET_LINK_LIBRARIES(khala_test gtest_main ${LIBUV} gtest glog gflags
                                 khala_base
                                 khala_serializer
                                 khala_network
                                 khala_third_party)

SET_TARGET_PROPERTIES(khala_test PROPERTIES LINK_SEARCH_END_STATIC 1)

TARGET_LINK_LIBRARIES(khala_test pthread)

