cmake_minimum_required(VERSION 3.5)

project(Game)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)


if(WIN32)
    add_custom_target(copy_dlls ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/vendor/win32/SFML-2.5.1/bin ${CMAKE_CURRENT_BINARY_DIR}
)
endif()


file(COPY res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# src headers
include_directories(src)

# Find SFML libraries


if(UNIX AND NOT APPLE)
	set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/linux/SFML-2.5.1/lib/cmake/SFML)
endif()

if(WIN32)
	set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/win32/SFML-2.5.1/lib/cmake/SFML)
endif()

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

# Add executable target
add_executable(Game src/main.cpp src/Input.cpp src/App.cpp src/Player.cpp src/Ball.cpp src/BallSpawner.cpp src/Score.cpp)

if(WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
endif()

# Link SFML libraries to executable
target_link_libraries(Game sfml-graphics sfml-window sfml-system)

if(UNIX AND NOT APPLE)
	target_link_libraries(Game stdc++)
endif()





