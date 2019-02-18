cmake_minimum_required(VERSION 3.13)
project(Lem_in C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(./libft)


add_executable(Lem_in main.c includes/lem_in.h)
target_include_directories(Lem_in PUBLIC ./includes)
target_link_libraries(Lem_in LIBFT)