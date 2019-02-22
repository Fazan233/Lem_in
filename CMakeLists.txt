cmake_minimum_required(VERSION 3.13)
project(Lem_in C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(./libft)


add_executable(Lem_in main.c includes/lem_in.h swap_2lnk_item.c quick_sort.c print_list.c add_vert.c sort_list.c quick_sort_for_intmas.c dijkstra.c get_min_vert.c)
target_include_directories(Lem_in PUBLIC ./includes)
target_link_libraries(Lem_in LIBFT)