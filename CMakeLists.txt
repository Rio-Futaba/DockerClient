cmake_minimum_required(VERSION 3.24)
project(DockerClient)

set(CMAKE_CXX_STANDARD 20)

add_library(DockerClient SHARED DockerClient.cpp DockerClient.h)