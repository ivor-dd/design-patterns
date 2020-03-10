cmake_minimum_required (VERSION 3.13.4)
project (algorithms)

set(TARGET_NAME_LIBRARY algorithms-library)
set(TARGET_NAME_EXECUTABLE main)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)




