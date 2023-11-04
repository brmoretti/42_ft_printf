NAME = libftprintf.a

LIB = libftprintf.a

CC = cc
CC_FLAGS = -Wall -Werror -Wextra

AR = ar
AR_FLAGS = rcs

INC_DIR = include
INC_FILES = ft_printf.h libft.h
INCLUDES = $(addprefix $(INC_DIR)/, $(INC_FILES))

LIB_DIR = lib
LIB_FILES = libft.a
LIBS = $(addprefix $(LIB_DIR)/, $(LIB_FILES))

SRC_DIR = src
SRC_FILES = ft_clear_tab.c ft_itoa_base_int.c ft_itoa_base_ulong.c ft_parse_char.c \
ft_parse_ptr.c ft_parse_uint.c ft_split_printf.c ft_itoa_base_uint.c ft_last_char.c \
ft_parse_int.c ft_parse_string.c ft_printf.c
SOURCES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR = build
OBJS = $(SRC_FILES:.c=.o)
BUILDS = $(addprefix $(BUILD_DIR)/, $(OBJS))

.PHONY: all clean fclean re bonus $(NAME) test

all: $(NAME)

$(NAME): $(BUILDS) $(INCLUDES) $(LIBS)
	$(AR) $(AR_FLAGS) $(LIB) $^
	@ echo $(LIB) "libftprintf.a is ready"

all1:
	$(AR) $(AR_FLAGS) $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@ echo "$< -> $@"
	@ cc -c $< -I./$(INC_DIR) -o $@ $(CC_FLAGS)

clean:
	@ rm -f $(BUILD_DIR)/*.*
	@ echo ".o files cleaned"

fclean: clean
	@ rm -f $(LIB)
	@ echo "$(LIB) is cleaned"

re: fclean all

test: $(BUILDS) $(INCLUDES) $(LIBS)
	$(CC) main.c -I./$(INC_DIR) -L./$(LIB_DIR) $(INCLUDES) $^
