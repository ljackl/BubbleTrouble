cmake_minimum_required(VERSION 3.9)
project(BubbleTrouble)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Game.cpp src/Game.hpp src/Blob.cpp src/Blob.hpp)
add_executable(BubbleTrouble ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(BubbleTrouble ${SFML_LIBRARIES})
endif()

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})