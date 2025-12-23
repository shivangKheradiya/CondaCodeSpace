cmake_minimum_required(VERSION 3.15)
project(sqlite_demo)

set(CMAKE_CXX_STANDARD 17)

# Tell CMake where conda libraries are
set(CMAKE_PREFIX_PATH "$ENV{CONDA_PREFIX}")

find_package(SQLite3 REQUIRED)
find_package(SOCI REQUIRED COMPONENTS core sqlite3 mysql)

include_directories(/workspaces/CondaCodeSpace/venv/include)

add_executable(sqlite_demo src/main.cpp)

target_link_directories(sqlite_demo PRIVATE /workspaces/CondaCodeSpace/venv/lib)

target_link_libraries(sqlite_demo 
                        PRIVATE 
                            SQLite::SQLite3
                            soci_core
                            soci_sqlite3
                            soci_mysql
)