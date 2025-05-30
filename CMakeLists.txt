cmake_minimum_required(VERSION 3.31)
project(numberOne)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         11.2.0
)
FetchContent_MakeAvailable(fmt)

add_executable(numberOne main.cpp
        sourceCodes/gameStart.cpp
        sourceCodes/gameStart.hpp
        sourceCodes/wordGenerator.cpp
        sourceCodes/wordGenerator.hpp
        sourceCodes/Menu.cpp
        sourceCodes/Menu.hpp
        sourceCodes/RecordMng.cpp
        sourceCodes/RecordMng.hpp
        sourceCodes/RecordsMenu.cpp
        sourceCodes/RecordsMenu.hpp
)
target_link_libraries(numberOne PRIVATE SFML::Graphics fmt)
