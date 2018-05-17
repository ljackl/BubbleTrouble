cmake_minimum_required(VERSION 3.9)
project(BubbleTrouble)

set(CMAKE_CXX_STANDARD 11)

# For library structure + catch unit testing refer:
# https://stackoverflow.com/questions/31363090/c-testing-classes-with-catch

# Includes
include_directories(include)

# Game state files
set(SOURCE_OTHER src/other/TestClass.cpp src/other/TestClass.hpp)
set(SOURCE_CORE src/core/Game.cpp src/core/Game.hpp src/core/Bubble.cpp src/core/Bubble.hpp src/core/Player.cpp src/core/Player.hpp src/core/Bullet.cpp src/core/Bullet.hpp src/core/GameEntity.cpp src/core/GameEntity.hpp)
set(SOURCE_MEDIA src/core/TextureManager.cpp src/core/TextureManager.hpp src/core/AnimationHandler.cpp src/core/AnimationHandler.hpp)
set(SOURCE_STATES src/states/GameState.hpp src/states/SplashGameState.hpp src/states/SplashGameState.cpp src/states/MenuGameState.hpp src/states/MenuGameState.cpp src/states/PlayGameState.hpp src/states/PlayGameState.cpp src/states/CreditGameState.hpp src/states/CreditGameState.cpp src/states/EndGameState.cpp src/states/EndGameState.hpp)
set(SOURCE_FILES ${SOURCE_CORE} ${SOURCE_MEDIA} ${SOURCE_STATES} ${SOURCE_OTHER})

# Create BubbleTrouble Library
add_library(BTL ${SOURCE_FILES})

# Create BubbleTrouble Executable
add_executable(BubbleTrouble src/main.cpp)
target_link_libraries(BubbleTrouble BTL)

# Create BubbleTrouble Test
add_executable(BubbleTrouble_TEST src/unit_tests/Test.cpp src/unit_tests/GameTest.cpp src/unit_tests/BulletTest.cpp src/unit_tests/BubbleTest.cpp)
target_link_libraries(BubbleTrouble_TEST BTL)

# SFML Loading
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(BubbleTrouble ${SFML_LIBRARIES})
    target_link_libraries(BubbleTrouble_TEST ${SFML_LIBRARIES})
endif()

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})