SRCDIR		= ./srcs/
SRCNAME		= ft_strlen.s \
			  ft_strcpy.s \
			  ft_strcmp.s \
			  ft_write.s \
			  ft_read.s \
			  ft_strdup.s
SRCS		= $(addprefix $(SRCDIR), $(SRCNAME))
OBJS		= $(SRCS:.s=.o)
INCLUDE		= -I./includes/libasm.h

BSRCDIR		= ./srcs/
BSRCNAME	= ft_atoi_base_bonus.s \
			  ft_list_push_front_bonus.s \
			  ft_list_size_bonus.s \
			  ft_list_sort_bonus.s \
			  ft_list_remove_if_bonus.s
BSRCS		= $(addprefix $(BSRCDIR), $(BSRCNAME))
BOBJS		= $(BSRCS:.s=.o)
BINCLUDE	= -I./includes/libasm_bonus.h

NAME		= libasm.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all		:	$(NAME)

%.o : %.s
	nasm -f macho64 $< -o $@

$(NAME)	:	$(OBJS)
			ar rcs $(NAME) $^

clean	:
			$(RM) $(OBJS) $(BOBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

bonus	:	$(OBJS) $(BOBJS)
			ar rcs $(NAME) $^

.PHONY	:	all clean fclean re bonus
