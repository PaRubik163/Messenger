cmake_minimum_required(VERSION 3.16)

# Название проекта
project(Client)

# Указание на использование C++ стандарта
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск пакета Qt
find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(Client main.cpp)