NAME = libft.a

LIB = libft.a

HEADER = libft.h

SRC_FILES = \
 ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
 ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
 ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
 ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
 ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
 ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
 ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRC_BONUS = \
 ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
 ft_lstlast_bonus.c  ft_lstmap_bonus.c  ft_lstnew_bonus.c  ft_lstsize_bonus.c

OBJS = $(SRC_FILES:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

.PHONY: all
all: $(OBJS) $(HEADER)
	@ ar rcs $(LIB) $^
	@ echo $(LIB) "successfully generated"

$(NAME) : all

.PHONY: bonus
bonus: $(OBJS) $(OBJS_BONUS) $(HEADER)
	@ ar rcs $(LIB) $^
	@ echo $(LIB) "successfully generated including bonus functions"

%.o: %.c
	@ echo "$< -> $@"
	@ cc -c $< -o $@ $(FLAGS)

.PHONY: clean
clean:
	@ rm -f *.o
	@ echo ".o files cleaned"

.PHONY: fclean
fclean: clean
	@ rm -f $(LIB)
	@ echo $(LIB) "cleaned"

.PHONY: re
re: fclean all
