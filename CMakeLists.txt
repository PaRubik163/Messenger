cmake_minimum_required(VERSION 3.16)

# Название проекта
project(Messenger)

# Указание на использование C++ стандарта
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Client)
add_subdirectory(Server)