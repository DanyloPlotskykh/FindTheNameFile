cmake_minimum_required(VERSION 3.12)

project(YourProjectName)

# Укажите стандарт C++ (например, C++11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавьте поддиректорию src
add_subdirectory(src)