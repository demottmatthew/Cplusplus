cmake_minimum_required(VERSION 3.2.2)
PROJECT(GraphLib CXX)

file(GLOB MYSOURCES    "src/*.cpp")
file(GLOB SOURCES      "graphlib/*.cpp")

set(FLTK_BUILD "C:/Users/Matthew/CMakeBuilds/0aa86ffc-88bf-9c32-9219-dbd81c1b5771/install/x86-Debug")
set(FLTK_LIBRARIES fltk fltk_gl fltk_forms fltk_images)
file(GLOB FLTK_LIBRARIES  ${FLTK_BUILD}/lib/*.lib)

ADD_EXECUTABLE(GraphLib ${SOURCES} ${MYSOURCES} )
target_include_directories(GraphLib PUBLIC ${FLTK_BUILD}/include  graphlib  )
target_link_libraries(GraphLib ${FLTK_LIBRARIES})
