#Default Cflags used for compilation
CFLAGS := -Wall -Wextra -MMD -g3

# Directory where are located header files
INCLUDE_DIR := includes

# Variable that will store flags command to include headers
INCLUDES := -I$(INCLUDE_DIR)

OBJ_DIR := objs

SRC_DIR := src

SRCS := $(shell find $(SRC_DIR) -name '*.c')

OBJS := $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(notdir $(basename $(SRCS)))))
DEPEND = $(OBJS:.o=.d)

# Directory where will the builded library will be stored
LIB_FOLDER := lib

# Library name
LIB_NAME := libft.a

# Library path
LIB := $(LIB_FOLDER)/$(LIB_NAME)

all : $(LIB)

$(LIB) : $(OBJS)
		@mkdir -p lib
		ar rcs $@ $^

# Rule to generate all object file and create OBJ_DIR if not exist
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Header dependencies. Adds the rules in the .d files, if they exists, in order to
# add headers as dependencies of obj files (see .d files).
# This rules will be merged with the previous rules.
-include $(DEPEND)

$(OBJ_DIR): ; @mkdir -p $@

# Removes all the build directories (objs, deps), executable and library and recreate them
.PHONY : re
re : fclean $(LIB)

# Removes all the build directories (objs, deps), executable and library
.PHONY : fclean
fclean : clean
		rm -rf $(LIB_FOLDER) $(OBJ_DIR)

# Removes the obj directory
.PHONY : clean
clean :
		rm -rf $(OBJ_DIR)