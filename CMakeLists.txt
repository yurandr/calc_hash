cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(calc_hash)
set(SRC_LIST calc_hash/i18n.cpp calc_hash/file_system.cpp calc_hash/arguments.cpp calc_hash/hash/crc32.cpp calc_hash/path/absolute.cpp calc_hash/path/relative.cpp calc_hash/calc_hash.cpp)
link_libraries(stdc++fs)
add_executable(${PROJECT_NAME} ${SRC_LIST})
