ODIR	= ./obj
MLXDIR	= minilib

HSRC	= headers
MSRCS	= main.c utils.c handle_error.c __init_struct.c malloc_utils.c read_utils.c map_valid.c

FILES	= $(MSRCS)
OBJS	= $(FILES:%.c=${ODIR}/%.o)
MLIB	= $(MLXDIR)/libmlx.a
CFLAGS	= -Wall -Werror -Wextra 

ifeq ($(DEBUG), debug)
	CFLAGS += -fsanitize=address -g3
endif
NAME	= so_long
CC		= gcc $(CFLAGS)

all: $(NAME)

minilibmake:
	@echo "Compiling minilib..."
	@make -C $(MLXDIR)

$(MLIB): minilibmake

$(NAME): $(OBJS) $(MLIB)
	@echo "Compiling so_long"
	@$(CC) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME) $(MLIB)

${ODIR}/%.o: %.c
	@mkdir -p $(ODIR)
	@printf "Generating %s                  \r" $<
	@$(CC) -Imlx -I$(MLXDIR) -I$(HSRC) -c $< -o $@

clean:
	@echo "Deleting objects"
	@make -sC $(MLXDIR)
	@rm -f $(OBJS)

fclean: clean
	@echo "Deleting executable"
	@make -C $(MLXDIR) clean
	@rm -f $(NAME)

re: fclean all 

.PHONY:	all clean fclean re
