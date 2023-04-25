cmake_minimum_required(VERSION 3.23)
project (Hashmap)

set(CMAKE_CXX_STANDARD 14)

add_executable(Hashmap Src/main.cpp Src/Fundamentals/DataNodeH.cpp Src/Fundamentals/DataNodeH.h Src/Fundamentals/FunctionsH.cpp Src/Fundamentals/FunctionsH.h Src/NodeMapH.cpp Src/NodeMapH.h Src/GenreMapH.cpp Src/GenreMapH.h)
