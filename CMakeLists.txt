cmake_minimum_required(VERSION 3.30)
project(connect4 C)

set(CMAKE_C_STANDARD 99)

add_executable(connect4 main.c
        game.c
        game.h
        gamehelper.c
        gamehelper.h
        windetection.h
        windetection.c
        onlinegamehelper.h
        onlinegamehelper.c
)
