cmake_minimum_required(VERSION 3.13)
project(Lem_in C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(./libft)


add_executable(Lem_in main.c includes/lem_in.h print_list.c add_vert.c find_list_ways.c graph_list_for_all_vert.c count_iterations.c bubble_sort_list.c BFS/bfs.c includes/bfs.h BFS/queue_operation.c is_ident_way.c count_amount_rooms.c del_mas_ways.c add_to_mas_res.c algorithms/algorithms.c algorithms/change_start.c includes/lem_algos.h algorithms/get_min_result.c parsing/parsing.c parsing/str_only_digits.c parsing/is_forbidden_chars.c parsing/count_chars.c parsing/room_validation.c parsing/add_to_map.c parsing/ft_error.c parsing/get_target.c parsing/link_validation.c way_operations.c get_short_way.c ants_go.c check_flags.c print_result.c ft_error_mode.c wish_list_operations.c psevdo_ants_go.c help.c)
target_include_directories(Lem_in PUBLIC ./includes)
target_link_libraries(Lem_in LIBFT)