cmake_minimum_required(VERSION 3.13)
project(Lem_in C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(./libft)


add_executable(Lem_in main.c includes/lem_in.h swap_2lnk_item.c quick_sort.c print_list.c add_vert.c sort_list.c quick_sort_for_intmas.c get_min_vert.c find_list_ways.c t_mas_ways.c parsing.c graph_list_for_all_vert.c includes/test.h list_lens.c dijkstraa.c)
target_include_directories(Lem_in PUBLIC ./includes)
target_link_libraries(Lem_in LIBFT)