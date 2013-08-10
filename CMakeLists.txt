project (2dplatformer)
cmake_minimum_required (VERSION 2.8)

set (CMAKE_CXX_FLAGS "-std=c++11")

find_package(SFML 2.0 REQUIRED audio graphics network system window)

include_directories (${SFML_INCLUDE_DIR})
link_libraries (${SFML_LIBRARIES})

file (GLOB_RECURSE PLATFORMER_SOURCES "src/*.cpp")
file (GLOB_RECURSE PLATFORMER_INCLUDES "src/*.hpp")

include_directories (PLATFORMER_INCLUDES)
add_executable (2dplatformer ${PLATFORMER_SOURCES})
target_link_libraries (2dplatformer ${SFML_LIBRARIES})
