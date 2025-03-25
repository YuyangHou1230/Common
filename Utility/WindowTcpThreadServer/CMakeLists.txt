cmake_minimum_required(VERSION 3.25)
project(Cpp_Study)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp_Study main.cpp Server.h Server.cpp)

# 添加Winsock库
target_link_libraries(Cpp_Study wsock32 ws2_32)
