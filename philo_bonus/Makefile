NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -pthread
INC_DIR = inc
OBJ_DIR = obj/
SRC_DIR = src/

# FSANITIZE	:= -fsanitize=address -g3

SRC_FILES	= main_bonus errors_bonus utils_libft_bonus utils_bonus philos_live_bonus actions_print_bonus

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

RM = rm -f



$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) -I $(INC_DIR)  -c $(CFLAGS) -MMD $< -o $@

all: 
	@$(MAKE) $(NAME)

bonus:
		@$(MAKE) all

-include $(DEPS)
$(NAME) :	$(OBJ) Makefile
		$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) -o $(NAME)



clean:
		$(RM) -r $(OBJ_DIR) $(DEPS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY : all clean re fclean makelibft
