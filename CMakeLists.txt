project (2dplatformer)
cmake_minimum_required (VERSION 2.8)

set(CMAKE_MODULE_PATH ${sfmle_SOURCE_DIR}/cmake/modules
                      ${CMAKE_MODULE_PATH})
                      
find_package(SFML 2.0 REQUIRED audio graphics network system window)

include_directories (${SFML_INCLUDE_DIR})
link_libraries (${SFML_LIBRARIES})

add_library (Tilemap.o src/Tilemap.cpp)
add_library (State.o src/State.cpp)
add_library (TitleState.o src/TitleState.cpp)
add_library (PlayState.o src/PlayState.cpp)
add_library (Player.o src/Player.cpp)

link_libraries (Player.o PlayState.o Tilemap.o State.o TitleState.o)

add_executable (2dplatformer src/Game.cpp)
target_link_libraries (2dplatformer Player.o PlayState.o Tilemap.o State.o TitleState.o)
