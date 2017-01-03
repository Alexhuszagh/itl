#   :author: The Regents of the University of California.
#   :license: Public Domain

cmake_minimum_required(VERSION 2.8)
project(itl CXX)

# TESTS
# -----

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
file(GLOB ITL_TESTS test/*.cpp)

add_subdirectory(googletest)
add_executable(ItlTests ${ITL_TESTS})
target_link_libraries(ItlTests
    gtest
    gtest_main
)

add_custom_target(check_itl
    COMMAND $<TARGET_FILE:ItlTests>
    DEPENDS ItlTests
)
