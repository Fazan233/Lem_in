NAME = lem-in

FLAGS = -Wall -Wextra -Werror

SRCS =	./srcs/add_to_mas_res.c\
		./srcs/add_vert.c\
		./srcs/ants_go.c\
		./srcs/bubble_sort_list.c\
		./srcs/check_flags.c\
		./srcs/count_amount_rooms.c\
		./srcs/count_iterations.c\
		./srcs/del_mas_ways.c\
		./srcs/find_list_ways.c\
		./srcs/ft_error_mode.c\
		./srcs/get_short_way.c\
		./srcs/graph_list_for_all_vert.c\
		./srcs/help.c\
		./srcs/is_ident_way.c\
		./srcs/main.c\
		./srcs/print_list.c\
		./srcs/print_result.c\
		./srcs/psevdo_ants_go.c\
		./srcs/way_operations.c\
		./srcs/wish_list_operations.c\
		./srcs/BFS/bfs.c\
		./srcs/BFS/queue_operation.c\
		./srcs/algorithms/algorithms.c\
		./srcs/algorithms/change_start.c\
		./srcs/algorithms/get_min_result.c\
		./srcs/parsing/check_sharp.c\
		./srcs/parsing/add_to_map.c\
		./srcs/parsing/count_chars.c\
		./srcs/parsing/ft_error.c\
		./srcs/parsing/get_target.c\
		./srcs/parsing/is_forbidden_chars.c\
		./srcs/parsing/link_validation.c\
		./srcs/parsing/parsing.c\
		./srcs/parsing/room_validation.c\
		./srcs/parsing/str_only_digits.c

INC =	./includes/lem_in.h\
		./includes/lem_algos.h

OBJ = $(SRCS:.c=.o)

all: libft $(NAME)

.PHONY : libft
libft:
	@make -C ./libft

$(NAME): $(OBJ) ./libft/libft.a
	@echo "Building of Lem-in..."
	@gcc -o $(NAME) $(OBJ) ./libft/libft.a

%.o: %.c $(INC) 
	gcc $(FLAGS) -I./includes -I./libft/includes -o $@ -c $<

clean:
	@make clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all