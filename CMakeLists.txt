cmake_minimum_required(VERSION 3.20)
project(Json)

set(CMAKE_CXX_STANDARD 14)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)
add_executable(Json main.cpp)

target_link_libraries(Json PRIVATE nlohmann_json::nlohmann_json)
