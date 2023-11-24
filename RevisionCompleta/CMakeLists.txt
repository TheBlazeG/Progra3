cmake_minimum_required(VERSION 3.26)
project(RevisionCompleta)

set(CMAKE_CXX_STANDARD 17)

add_executable(RevisionCompleta main.cpp
        SLList.h
        DLList.h
        Stack.h
        Queue.h)
