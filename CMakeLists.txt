cmake_minimum_required(VERSION 3.15)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project
        alle.cpp
        Alle.h
        board.cpp
        board.h
        buttons.cpp
        buttons.h
        main.cpp
        Puzzel.cpp
        Puzzel.h
        Puzzel0.h
        Puzzel1.cpp
        Puzzel1.h
        Puzzel12.cpp
        Puzzel12.h
        Puzzel14.cpp
        Puzzel14.h
        Puzzel21.cpp
        Puzzel21.h
        Puzzel22.cpp
        Puzzel22.h
        Puzzel22dr.cpp
        Puzzel22dr.h
        Puzzel41.cpp
        Puzzel41.h
        structs.h)
include_directories(./include)
link_directories(./lib/allegro5)
#connect all the libraries
set(allegro5_LIBS /./lib/allegro5/liballegro.so /./lib/allegro5/liballegro_primitives.so)

#target_link_libraries(PercolationVisualizer ${allegro5_LIBS})

