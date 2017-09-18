cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(ucc C)

set(ucc_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(ucc_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)

file(GLOB_RECURSE ucc_HDRS ${ucc_HDRS} ${ucc_INC_DIR}/ucc/*.h)
set(ucc_HDR ${ucc_INC_DIR}/ucc.h)

add_library(ucc INTERFACE)
target_include_directories(ucc INTERFACE ${ucc_INC_DIR})

get_directory_property(ucc_PARENT PARENT_DIRECTORY)
if (NOT ${ucc_PARENT})
  set(ucc_DEVEL TRUE)
elseif (NOT ${ucc_DEVEL})
  set(ucc_DEVEL FALSE)
endif ()
if (${ucc_DEVEL} AND EXISTS ${ucc_TEST_DIR})
  if (NOT ucc_PARENT)
    enable_testing()
  endif ()

  file(GLOB ucc_TEST_SRCS ${ucc_TEST_SRCS} ${ucc_TEST_DIR}/*.c)
  foreach (ucc_TEST_SRC ${ucc_TEST_SRCS})
    get_filename_component(ucc_TEST_NAME ${ucc_TEST_SRC} NAME_WE)
    add_executable(test_${ucc_TEST_NAME} ${ucc_TEST_SRC})
    add_dependencies(test_${ucc_TEST_NAME} ucc)
    target_link_libraries(test_${ucc_TEST_NAME} ucc)
    add_test(${ucc_TEST_NAME} test_${ucc_TEST_NAME})
  endforeach ()
endif ()

install(FILES ${ucc_HDRS}
  DESTINATION include/ucc)
install(FILES ${ucc_HDR}
  DESTINATION include)
