cmake_minimum_required(VERSION 3.7)
project(AED2)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES matrix.c Tree.c Tree.h Hash.c Hash.h Dados.c Dados.h)
add_executable(AED2 ${SOURCE_FILES})