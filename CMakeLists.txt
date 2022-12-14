CMAKE_MINIMUM_REQUIRED(VERSION 2.9)


PROJECT(graph)

SET(SOURCES
           arcGraph.cpp
           listGraph.cpp
           matrixGraph.cpp
           setGraph.cpp)

ADD_EXECUTABLE(graph main.cpp ${SOURCES})
