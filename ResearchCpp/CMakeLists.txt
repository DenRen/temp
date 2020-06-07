cmake_minimum_required(VERSION 3.14)
project(ResearchCpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(ResearchCpp main.cpp Vector.h Vector.cpp Temp_.h Classes/temperature.cpp Classes/temperature.h Classes/turbo.cpp Classes/turbo.h)