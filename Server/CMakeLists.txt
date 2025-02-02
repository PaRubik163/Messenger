cmake_minimum_required(VERSION 3.16)

# Название проекта
project(Server)

set(CMAKE_AUTOMOC ON)       # Включает автоматическую генерацию .moc-файлов
set(CMAKE_AUTORCC ON)       # Включает автоматическую обработку .qrc-файлов
set(CMAKE_AUTOUIC ON)       # Включает автоматическую обработку .ui-файлов

# Указание на использование C++ стандарта
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск пакета Qt
find_package(Qt5 REQUIRED COMPONENTS Widgets Network)


add_executable(Server main.cpp
                server.cpp server.h
                 user.cpp user.h
                 checknameresponse.h)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Network)
