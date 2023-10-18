cmake_minimum_required(VERSION 3.5.0)
project(BSC-Engine)

# Generates a `compile_commands.json` that can be used for autocompletion
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(. include)
add_library(${PROJECT_NAME} STATIC BSC-Engine.c glad.c io/io.c render/render.c render/shader.c tools/debug.c window/window.c)