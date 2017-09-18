cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(ucc C)
set(CMAKE_C_STANDARD 90)
set(PROJ ${PROJECT_NAME})
set(${PROJ}_VENDOR "uael")
set(${PROJ}_CONTACT "github.com/uael/ucc/issues")
set(${PROJ}_SUMMARY "uael Cross-Compiler c header module")
set(${PROJ}_MAJOR 0)
set(${PROJ}_MINOR 1)
set(${PROJ}_PATCH 0)
set(${PROJ}_README README.md)
set(${PROJ}_LICENSE LICENSE)
set(${PROJ}_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(${PROJ}_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)

get_directory_property(${PROJ}_PARENT PARENT_DIRECTORY)
if (NOT ${PROJ}_PARENT)
  set(${PROJ}_DEVEL TRUE)
endif ()

set(${PROJ}_HEADERS)
set(${PROJ}_SOURCES)

if (EXISTS ${${PROJ}_INCLUDE_DIR})
  file(GLOB_RECURSE ${PROJ}_HEADERS ${${PROJ}_HEADERS}
    ${${PROJ}_INCLUDE_DIR}/${PROJ}/*.h)
  file(GLOB ${PROJ}_MODULES ${${PROJ}_MODULES}
    ${${PROJ}_INCLUDE_DIR}/*/)
  foreach (MODULE ${${PROJ}_MODULES})
    file(GLOB_RECURSE ${PROJ}_HEADERS ${${PROJ}_HEADERS}
      ${MODULE}/*.h)
  endforeach ()
endif ()

if (EXISTS ${${PROJ}_INCLUDE_DIR}/${PROJ}.h)
  set(${PROJ}_HEADER ${${PROJ}_INCLUDE_DIR}/${PROJ}.h)
else ()
  set(${PROJ}_HEADER)
endif ()

add_library(${PROJ} INTERFACE)

if (EXISTS ${${PROJ}_INCLUDE_DIR})
  target_include_directories(${PROJ} INTERFACE
    ${${PROJ}_INCLUDE_DIR})
endif ()

#if (${PROJ}_DEVEL)
  if (EXISTS ${${PROJ}_TEST_DIR})
    enable_testing()

    file(GLOB ctest_SOURCES ${ctest_SOURCES} ${${PROJ}_TEST_DIR}/*.c)
    foreach (ctest_SRC ${ctest_SOURCES})
      get_filename_component(ctest_NAME ${ctest_SRC} NAME_WE)
      add_executable(test_${ctest_NAME} ${ctest_SRC})
      add_dependencies(test_${ctest_NAME} ${PROJ})
      target_link_libraries(test_${ctest_NAME} ${PROJ})
      add_test(${ctest_NAME} test_${ctest_NAME})
    endforeach ()
  endif ()
#endif ()

install(TARGETS ${PROJ}
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  PUBLIC_HEADER DESTINATION include/${PROJ})
if (EXISTS ${${PROJ}_INCLUDE_DIR}/${PROJ}.h)
  install(FILES ${${PROJ}_INCLUDE_DIR}/${PROJ}.h
    DESTINATION include)
endif ()
