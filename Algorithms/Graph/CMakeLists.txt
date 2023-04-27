cmake_minimum_required(VERSION 3.23)
project(Graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graph Src/main.cpp Src/DataNodeT.cpp Src/DataNodeT.h Src/gameTreeT.cpp Src/gameTreeT.h Src/FunctionsT.h Src/FunctionsT.cpp)
