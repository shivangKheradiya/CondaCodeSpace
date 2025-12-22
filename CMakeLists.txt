cmake_minimum_required(VERSION 3.15)
project(sqlite_demo)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)

add_executable(sqlite_demo src/main.cpp)

target_link_libraries(sqlite_demo PRIVATE SQLite::SQLite3)