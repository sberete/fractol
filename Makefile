CC = cc
CFLAGS = -Werror -Wextra -Wall -MMD -g3 -fPIC
INCLUDES = -Iincludes -I./lib/ft_printf/includes -I./lib/libft/includes -I./minilibx-linux
SRC_DIR = src
SRC_DIR_BONUS = src_bonus
OBJ_DIR = objs
OBJ_DIR_BONUS = objs_bonus
MLX = minilibx-linux
MLXFLAGS = -L$(MLX) -lmlx -lXext -lX11 -lm
LIBPRINTF = lib/ft_printf/lib/libprintf.a
LIBFT = lib/libft/lib/libft.a

SRCS = $(shell find $(SRC_DIR) -name '*.c')
SRCS_BONUS = $(shell find $(SRC_DIR_BONUS) -name '*_bonus.c')
OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/,$(addsuffix .o,$(notdir $(basename $(SRCS_BONUS)))))

DEPENDS = $(OBJS:.o=.d)

NAME = fractol
NAME_BONUS = fractol_bonus
-include $(DEPEND)

.PHONY: all
all: $(MLX) $(NAME)

.PHONY: bonus
bonus: $(MLX) $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBPRINTF) $(LIBFT)
			$(MAKE) -C $(MLX)
			$(CC) $^ -o $@ $(MLXFLAGS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBPRINTF) $(LIBFT)
			$(MAKE) -C $(MLX)
			$(CC) $^ -o $@ $(MLXFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

$(LIBPRINTF):
	$(MAKE) -C lib/ft_printf

$(LIBFT):
	$(MAKE) -C lib/libft

$(MLX):
	git clone https://github.com/42Paris/minilibx-linux.git $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)
	rm -rf $(MLX)
	$(MAKE) -C lib/ft_printf clean
	$(MAKE) -C lib/libft clean
.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	rm -rf $(MLX)
	$(MAKE) -C lib/ft_printf fclean
	$(MAKE) -C lib/libft fclean

.PHONY:
re: fclean all