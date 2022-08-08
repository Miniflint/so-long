GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m

SDIR	= ./src
MDIR	= $(SDIR)/main
UDIR	= $(SDIR)/utils
MUDIR	= $(MDIR)/utils_mlx
MLXDIR	= minilib

MSRCS	= main.c __init__.c handle_movement.c map_checker.c change_image.c regen_map.c
USRCS	= ft_strlen.c handle_error.c ft_strdup.c free_mem.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c parse_map.c ft_itoa.c ft_strchr.c random_utils.c
MUSRC	= close_win.c key_event.c

OSSRCS	= $(addprefix $(MDIR)/,$(MSRCS))
OUSRCS	= $(addprefix $(UDIR)/,$(USRCS))
MUSRCS	= $(addprefix $(MUDIR)/,$(MUSRC))
FILES	= $(OSSRCS) $(OUSRCS) $(MUSRCS)
OBJS	= $(FILES:.c=.o)
MLIB	= $(MLXDIR)/libmlx.a
CFLAGS	= -Wall -Werror -Wextra 

ifeq ($(DEBUG), debug)
	CFLAGS += -fsanitize=address -g3
endif
NAME	= so_long
CC		= gcc $(CFLAGS)

all: $(NAME)

minilibmake:
	@echo "$(GREEN)\n\nCompiling minilib..."
	@make -C $(MLXDIR)
	@echo "$(GREEN)Done"

$(NAME): $(OBJS) minilibmake
	@echo "$(GREEN)\n\nCompiling so_long..."
	@$(CC) -I$(MLXDIR) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME) $(MLIB)
	@echo "$(GREEN)Done"

%.o: %.c
	@echo "$(YELLOW)Generating so_long objects..." $@
	$(CC) -Imlx -c $< -o $@

clean:
	@echo "$(RED)\nDeleting objects..."
	@make -C $(MLXDIR) clean
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)\nDeleting executable..."
	@rm -f $(NAME)

re: fclean all 

.PHONY:	clean fclean all re minilibmake