cmake_minimum_required(VERSION 3.16)

# Название проекта
project(Client)

set(CMAKE_AUTOMOC ON)       # Включает автоматическую генерацию .moc-файлов
set(CMAKE_AUTORCC ON)       # Включает автоматическую обработку .qrc-файлов
set(CMAKE_AUTOUIC ON)       # Включает автоматическую обработку .ui-файлов

# Указание на использование C++ стандарта
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск пакета Qt
find_package(Qt5 REQUIRED COMPONENTS Widgets Network)

add_executable(Client main.cpp
                user.cpp user.h
                widget.cpp widget.h widget.ui
                login.cpp login.h)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets Qt5::Network)
