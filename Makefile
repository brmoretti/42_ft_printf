NAME		=	libftprintf.a
LIB			=	libftprintf.a

CC			=	cc
CC_FLAGS	=	-Wall -Werror -Wextra

AR				=	ar
AR_FLAGS		=	rcs

INC_DIR			=	include
INCLUDES		=	-I./$(INC_DIR)

SRC_DIR 		=	src
SRC_FILES		=	ft_atoi.c				\
					ft_bzero.c				\
					ft_calloc.c				\
					ft_clear_tab.c			\
					ft_itoa_base_int.c		\
					ft_itoa_base_uint.c		\
					ft_itoa_base_ulong.c	\
					ft_last_char.c			\
					ft_parse_char.c			\
					ft_parse_int.c			\
					ft_parse_ptr.c			\
					ft_parse_string.c		\
					ft_parse_uint.c			\
					ft_printf.c				\
					ft_putstr_len.c			\
					ft_split_printf.c		\
					ft_strchr.c				\
					ft_strdup.c				\
					ft_strjoin.c			\
					ft_strlen.c
SOURCES 		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

SRC_DIR_BONUS	= src_bonus
SRC_FILES_BONUS	=	ft_atoi.c   ft_calloc.c     ft_itoa_base_int.c   ft_itoa_base_ulong.c  ft_parse_char.c  ft_parse_ptr.c     ft_parse_uint.c  ft_putstr_len.c    ft_strchr.c  ft_strjoin.c \
ft_bzero.c  ft_clear_tab.c  ft_itoa_base_uint.c  ft_last_char.c        ft_parse_int.c   ft_parse_string.c  ft_printf.c      ft_split_printf.c  ft_strdup.c  ft_strlen.c

SOURCES_BONUS 	=	$(addprefix $(SRC_DIR_BONUS)/, $(SRC_FILES_BONUS))

BUILD_DIR 	=	build
BUILD_DIR_BONUS = build_bonus
OBJS		=	$(SRC_FILES:.c=.o)
OBJS_BONUS	=	$(SRC_FILES_BONUS:.c=.o)
BUILDS		=	$(addprefix $(BUILD_DIR)/, $(OBJS))
BUILDS_BONUS	=	$(addprefix $(BUILD_DIR)/, $(OBJS_BONUS))

ifdef	M_BONUS
		$(OBJS) = $(OBJS_BONUS)
endif

.PHONY: all clean fclean re bonus test

all: $(NAME)

# bonus:
#	@ make M_BONUS=TRUE --no-print-directory

$(NAME): $(BUILDS)
	@ echo "$(LIB) is ready"

bonus: $(BUILDS_BONUS)
	@ echo "g flag is on"
	@ echo "$(LIB) is ready"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@ echo "$< -> $@"
	@ cc -c $< $(INCLUDES) -o $@ $(CC_FLAGS)
	@ $(AR) $(AR_FLAGS) $(LIB) $@

$(BUILD_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@ echo "$< -> $@"
	@ cc -c $< $(INCLUDES) $(LINCLUDES) -o $@ $(CC_FLAGS) -g
	@ $(AR) $(AR_FLAGS) $(LIB) $@

clean:
	@ rm -f $(BUILD_DIR)/*.*
	@ echo ".o files cleaned"

fclean: clean
	@ rm -f $(LIB)
	@ echo "$(LIB) is cleaned"

re: fclean all

test: $(BUILDS_BONUS)
	$(CC) test.c $(INCLUDES) $^ -o test.out -g

test_bonus: $(BUILDS_BONUS) $(LIBFT)
	$(CC) test.c $(INCLUDES) $(LINCLUDES) $^ -o test.out

test2: $(BUILDS) $(INCLUDES) $(LIBFT)
	$(CC) test2.c -I./$(INC_DIR) $(LIBFT) $(INCLUDES) $^ -o test2.out

test_f:
	$(CC) src_bonus/ft_get_flags_bonus.c -I./$(INC_DIR) $(LIBFT) $(INCLUDES) $^ -o test3.out -g
