
cmake_minimum_required(VERSION 3.12)
project(reveck VERSION 0.0.1.0 LANGUAGES CXX)

option(ENABLE_WARNINGS_SETTINGS "Allow target_set_warnings to add flags and defines.
                                 Set this to OFF if you want to provide your own warning parameters." ON)
option(ENABLE_DOCTESTS "Include tests in the library. Setting this to OFF will remove all doctest related code.
                        Tests in tests/*.cpp will still be enabled." ON)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(Warnings)
include(Doctest)

set(SOURCES
    src/repl/repl.cc
)
set(TESTFILES
    tests/main.cc
)

set(LIBRARY_NAME reveck)

add_library(${LIBRARY_NAME} OBJECT ${SOURCES})

target_link_libraries(${LIBRARY_NAME} PUBLIC doctest)

target_set_warnings(${LIBRARY_NAME} ENABLE ALL AS_ERROR ALL DISABLE Annoying)

add_executable(repl repl/repl.cc)
target_link_libraries(repl PRIVATE ${LIBRARY_NAME})  # Link the executable to library (if it uses it).
target_set_warnings(repl ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).

# Set the properties you require, e.g. what C++ standard to use. Here applied to library and main (change as needed).
set_target_properties(
    ${LIBRARY_NAME} repl
      PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_subdirectory(tests)