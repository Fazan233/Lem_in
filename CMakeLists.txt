cmake_minimum_required(VERSION 3.13)
project(Lem_in C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(./libft)

add_executable(Lem_in srcs/main.c includes/lem_in.h srcs/print_list.c srcs/add_vert.c srcs/find_list_ways.c srcs/graph_list_for_all_vert.c srcs/count_iterations.c srcs/bubble_sort_list.c srcs/BFS/bfs.c srcs/BFS/queue_operation.c srcs/is_ident_way.c srcs/count_amount_rooms.c srcs/del_mas_ways.c srcs/add_to_mas_res.c srcs/algorithms/algorithms.c srcs/algorithms/change_start.c includes/lem_algos.h srcs/algorithms/get_min_result.c srcs/parsing/parsing.c srcs/parsing/str_only_digits.c srcs/parsing/is_forbidden_chars.c srcs/parsing/count_chars.c srcs/parsing/room_validation.c srcs/parsing/add_to_map.c srcs/parsing/ft_error.c srcs/parsing/get_target.c srcs/parsing/link_validation.c srcs/way_operations.c srcs/get_short_way.c srcs/ants_go.c srcs/check_flags.c srcs/print_result.c srcs/ft_error_mode.c srcs/wish_list_operations.c srcs/psevdo_ants_go.c srcs/help.c srcs/parsing/check_sharp.c)
target_include_directories(Lem_in PUBLIC ./includes)
target_link_libraries(Lem_in LIBFT)