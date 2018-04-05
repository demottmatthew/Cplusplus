# in visual studio: https://blogs.msdn.microsoft.com/vcblog/2016/10/05/cmake-support-in-visual-studio/

cmake_minimum_required(VERSION 3.2.2)
project(poly)

add_subdirectory(PolyLib)
add_subdirectory(PolyEval)
add_subdirectory(PolyCalc)

add_subdirectory(PolyTest)

