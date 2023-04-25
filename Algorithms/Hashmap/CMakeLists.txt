cmake_minimum_required(VERSION 3.23)
project (Hashmap)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hashmap Src/main.cpp Src/Fundamentals/DataNode.cpp Src/Fundamentals/DataNode.h Src/Fundamentals/ReadData.cpp Src/Fundamentals/ReadData.h Src/NodeMap.cpp Src/NodeMap.h Src/GenreMap.cpp Src/GenreMap.h)
