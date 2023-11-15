NAME			=	libftprintf.a
LIB				=	libftprintf.a

CC				=	cc
CC_FLAGS		=	-Wall -Werror -Wextra

AR				=	ar
AR_FLAGS		=	rcs

INC_DIR			=	include
INCLUDES		=	-I./$(INC_DIR)

SRC_DIR 		=	src
SRC_FILES		=	ft_atoi.c					\
					ft_bzero.c					\
					ft_calloc.c					\
					ft_clear_tab.c				\
					ft_dash_flag_bonus.c		\
					ft_get_flags_bonus.c		\
					ft_isdigit.c				\
					ft_itoa_base_int.c			\
					ft_itoa_base_uint.c			\
					ft_itoa_base_ulong.c		\
					ft_last_char.c				\
					ft_parse_char.c				\
					ft_parse_int.c				\
					ft_parse_ptr.c				\
					ft_parse_string.c			\
					ft_parse_uint.c				\
					ft_precision_int_bonus.c	\
					ft_precision_uint_bonus.c	\
					ft_printf.c					\
					ft_putstr_len.c				\
					ft_putstr_len_limit.c		\
					ft_split_printf.c			\
					ft_strchr.c					\
					ft_strdup.c					\
					ft_strjoin.c				\
					ft_strlen.c					\
					ft_zero_flag_int_bonus.c	\
					ft_zero_flag_uint_bonus.c
SOURCES 		=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR 		=	build
OBJS			=	$(SRC_FILES:.c=.o)
BUILDS			=	$(addprefix $(BUILD_DIR)/, $(OBJS))

###---			COLORS				---###
RED				=	\033[0;31m
YELLOW			=	\033[0;33m
BLUE 			=	\033[0;34m
MAGENTA			=	\033[0;35m
CYAN			=	\033[0;36m
WHITE			=	\033[0;37m
GREEN 			=	\033[0;32m
DEFAULT			=	\033[0:0m
#----------------------------------------#

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): bonus

bonus: $(BUILD_DIR) $(BUILDS)
	@ echo "$(GREEN)$(LIB) is ready$(DEFAULT)"

$(BUILD_DIR):
	@ mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@ echo "$(MAGENTA)$< $(BLUE)->$(GREEN) $@$(DEFAULT)"
	@ $(CC) -c $< $(INCLUDES) -o $@ $(CC_FLAGS)
	@ $(AR) $(AR_FLAGS) $(LIB) $@

clean:
	@ rm -rf $(BUILD_DIR)
	@ echo "$(MAGENTA)./$(BUILD_DIR)$(DEFAULT) have been cleaned"

fclean: clean
	@ rm -f $(LIB)
	@ echo "$(MAGENTA)$(LIB)$(DEFAULT) have been cleaned"

re: fclean all
