cmake_minimum_required(VERSION 3.7)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

# Find SDL2
find_package(SDL2 REQUIRED)
if (NOT SDL2_FOUND)
    message(FATAL_ERROR "SDL2 not found! Please install SDL2.")
endif()

# Add executable and source files
add_executable(SnakeGame
    main.cpp
    src/gameManager.cpp
    src/gameDataBase.cpp
    src/game.cpp
    src/controller.cpp
    src/renderer.cpp
    src/snake.cpp
)

# Include directories and link SDL2 libraries
target_include_directories(SnakeGame PRIVATE
    ${SDL2_INCLUDE_DIRS}
    inc
)

# Link SDL2, and pthread libraries
target_link_libraries(SnakeGame PRIVATE
    ${SDL2_LIBRARIES}
    pthread
)

# Optional: Use target_compile_options to add compiler flags
target_compile_options(SnakeGame PRIVATE -Wall)
