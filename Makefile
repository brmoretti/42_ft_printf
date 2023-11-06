NAME		=	libftprintf.a
LIB			=	libftprintf.a

CC			=	cc
CC_FLAGS	=	-Wall -Werror -Wextra

AR				=	ar
AR_FLAGS		=	rcs

LIBFT_PATH		=	libft
LIBFT			=	$(LIBFT_PATH)/libft.a

INC_DIR			=	include
INC_FILES		=	ft_printf.h
INCLUDES		=	-I./$(INC_DIR) -I./$(LIBFT_PATH)
LINCLUDES		=	-L./$(LIBFT_PATH) -lft

SRC_DIR 		=	src
SRC_FILES		=	ft_clear_tab.c ft_itoa_base_int.c ft_itoa_base_ulong.c ft_parse_char.c \
					ft_parse_ptr.c ft_parse_uint.c ft_split_printf.c ft_itoa_base_uint.c \
					ft_last_char.c ft_parse_int.c ft_parse_string.c ft_printf.c
SOURCES 		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC_DIR_BONUS	= src_bonus
SRC_FILES_BONUS	=	ft_clear_tab_bonus.c ft_itoa_base_uint_bonus.c ft_parse_ptr_bonus.c \
ft_conversion_hex.c ft_itoa_base_ulong_bonus.c ft_parse_string_bonus.c \
ft_flags_flow_bonus.c ft_last_char_bonus.c ft_parse_uint_bonus.c \
ft_get_flags_bonus.c ft_parse_char_bonus.c ft_printf_bonus.c \
ft_itoa_base_int_bonus.c ft_parse_int_bonus.c ft_split_printf_bonus.c

SOURCES_BONUS 	=	$(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_BONUS))

BUILD_DIR 	=	build
BUILD_DIR_BONUS = build_bonus
OBJS		=	$(SRC_FILES:.c=.o)
OBJS_BONUS	=	$(SRC_FILES_BONUS:.c=.o)
BUILDS		=	$(addprefix $(BUILD_DIR)/, $(OBJS))
BUILDS_BONUS	=	$(addprefix $(BUILD_DIR_BONUS)/, $(OBJS_BONUS))

ifdef	M_BONUS
		$(OBJS) = $(OBJS_BONUS)
endif

.PHONY: all clean fclean re bonus test

all: $(NAME)

bonus:
	@ make M_BONUS=TRUE --no-print-directory

$(NAME): $(LIBFT) $(BUILDS)
	@ $(AR) $(AR_FLAGS) $(LIB) $^ -v
	@ echo "$(LIB) is ready"

$(LIBFT):
	make -C ./$(LIBFT_PATH) all --no-print-directory

$(BUILD_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@ echo "$< -> $@"
	@ cc -c $< $(INCLUDES) $(LINCLUDES) -o $@ $(CC_FLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@ echo "$< -> $@"
	@ cc -c $< $(INCLUDES) -o $@ $(CC_FLAGS)

clean:
	@ make -C ./$(LIBFT_PATH) clean --no-print-directory
	@ rm -f $(BUILD_DIR)/*.*
	@ echo ".o files cleaned"

fclean: clean
	@ make -C $(LIBFT_PATH) fclean --no-print-directory
	@ rm -f $(LIB)
	@ echo "$(LIB) is cleaned"

re: fclean all

test: $(BUILDS) $(LIBFT)
	$(CC) test.c $(INCLUDES) $(LINCLUDES) $^ -o test.out

test_bonus: $(BUILDS_BONUS) $(LIBFT)
	$(CC) test.c $(INCLUDES) $(LINCLUDES) $^ -o test.out

test2: $(BUILDS) $(INCLUDES) $(LIBFT)
	$(CC) test2.c -I./$(INC_DIR) $(LIBFT) $(INCLUDES) $^ -o test2.out

test_f:
	$(CC) src_bonus/ft_get_flags_bonus.c -I./$(INC_DIR) $(LIBFT) $(INCLUDES) $^ -o test3.out -g
