NAME = fractol

#########
RM = rm -f
CC = cc
CFLAGS = -Werror -Wextra -Wall #-g -fsanitize=address
#########

#########
FILES = main mandelbrot julia burn_ship params hooks init
FILES_BONUS = main_bonus mandelbrot_bonus julia_bonus burn_ship_bonus params_bonus hooks_bonus init_bonus

SRC = $(addsuffix .c, $(FILES))
SRC_BONUS = $(addsuffix .c, $(FILES_BONUS))

vpath %.c srcs srcs_bonus
#########

#########
OBJ_DIR = objs
OBJ_DIR_BONUS = objs_bonus
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEP = $(addsuffix .d, $(basename $(OBJ)))
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS:.c=.o))
DEP_BONUS = $(addsuffix .d, $(basename $(OBJ_BONUS)))
#########

########
MLX_DIR = inc/mlx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
########


#########
$(OBJ_DIR)/%.o: %.c	
	@mkdir -p $(@D)
	${CC} $(CFLAGS) -Imlx -MMD -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c	
	@mkdir -p $(@D)
	${CC} $(CFLAGS) -Imlx -MMD -c $< -o $@

all:
	@$(MAKE) -C $(MLX_DIR) --no-print-directory
	$(MAKE) $(NAME) --no-print-directory

bonus:
	$(MAKE) BONUS=1 all

ifndef BONUS

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo "EVERYTHING DONE  "

else

$(NAME): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME)
	@echo "EVERYTHING DONE (BONUS)  "

endif

clean:
	$(MAKE) clean -C $(MLX_DIR) --no-print-directory
	$(RM) $(OBJ) $(DEP) $(OBJ_BONUS) $(DEP_BONUS) --no-print-directory
	$(RM) -r $(OBJ_DIR) $(OBJ_DIR_BONUS) --no-print-directory
	@echo "OBJECTS REMOVED   "

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) --no-print-directory
	@echo "EVERYTHING REMOVED   "

re:	fclean all

.PHONY: all clean fclean re bonus

-include $(DEP)
-include $(DEP_BONUS)

#########
