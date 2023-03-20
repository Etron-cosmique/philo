CC = clang

NAME = philosopher

DIR_S = srcs
DIR_O = obj
HEADER = inc/
RM = rm -rf

LIBFT = libft

SOURCES =   main.c \
			utils.c \
			init.c \
			threads_utils.c \
			checkers.c \
			superviseur.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

CFLAGS = -g3 -Wall -Werror -Wextra -I $(HEADER)

LFLAGS = -L $(LIBFT) -lft

all: $(NAME)

$(OBJS) : $(DIR_O)/%.o : $(DIR_S)/%.c
		@mkdir -p $(dir $@)
# $(CC) $(CFLAGS) -c $< -o $@
		$(CC) $(CFLAGS) -I/usr/include -O3 -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
	@make -C $(LIBFT)
	$(CC)	$(CFLAGS)	$(OBJS)	$(LFLAGS) -o	$(NAME)

norme:
	@echo
	norminette	./$(HEADER)
	@echo
	norminette	./$(DIR_S)

# val:
# 	make -s -j all
# 	valgrind				\
# 		--show-leak-kinds=all	\
# 		--track-origins=yes		\
# 		--leak-check=full		\
# 		./\$(NAME) maps/maps_test/42.fdf
		
#./\$(NAME) maps/test5.fdf

bonus: all

clean:
	$(RM) $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all