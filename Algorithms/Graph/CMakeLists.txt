cmake_minimum_required(VERSION 3.23)
project(Graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(Graph Src/main.cpp Src/DataNode.cpp Src/DataNode.h Src/ReadData.cpp Src/ReadData.h)
