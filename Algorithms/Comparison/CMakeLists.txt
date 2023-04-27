cmake_minimum_required(VERSION 3.23)
project(Comparison)

set(CMAKE_CXX_STANDARD 14)

add_executable(Comparison main.cpp SrcH/GenreMapH.cpp SrcH/GenreMapH.h SrcH/NodeMapH.cpp SrcH/NodeMapH.h SrcH/Fundamentals/DataNodeH.cpp SrcH/Fundamentals/DataNodeH.h SrcH/Fundamentals/FunctionsH.cpp SrcH/Fundamentals/FunctionsH.h
        SrcT/DataNodeT.cpp SrcT/DataNodeT.h SrcT/FunctionsT.cpp SrcT/FunctionsT.h SrcT/gameTreeT.cpp SrcT/gameTreeT.h)
