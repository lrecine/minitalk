NAMEC = client
NAMES = server
LIBFT = libft.a
BONUS_NAMEC = client_bonus
BONUS_NAMES = server_bonus
PRINTF = libftprintf.a
SRCC_FILES =	client.c
SRCS_FILES =	server.c
BONUSC_FILES = client_bonus.c
BONUSS_FILES = server_bonus.c
SRC_DIR = src/
BONUS_DIR = bonus/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
BONUSC = $(addprefix $(BONUS_DIR), $(BONUSC_FILES))
BONUSS = $(addprefix $(BONUS_DIR), $(BONUSS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
OBJBC = ${BONUSC:.c=.o}
OBJBS = ${BONUSS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C printf
		@make -C libft
		@cp libft/libft.a .
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) libft/$(LIBFT) printf/$(PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C printf
		@make -C libft
		@cp libft/libft.a .
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) libft/$(LIBFT) printf/$(PRINTF) -o $(NAMES)

bonus : $(BONUS_NAMEC) $(BONUS_NAMES)

$(BONUS_NAMEC) : $(OBJBC)
		@make -C printf
		$(CC) $(CFLAGS) $(OBJBC) $(INCLUDE) libft/$(LIBFT) printf/$(PRINTF) -o $(BONUS_NAMEC)	

$(BONUS_NAMES) : $(OBJBS)
		@make -C printf
		$(CC) $(CFLAGS) $(OBJBS) $(INCLUDE) libft/$(LIBFT) printf/$(PRINTF) -o $(BONUS_NAMES)

clean :
		make clean -C printf
		@make fclean -C libft
		${RM} ${OBJC}
		${RM} ${OBJS}
		${RM} ${OBJBC}
		${RM} ${OBJBS}

fclean : clean
		@make fclean -C printf
		@make fclean -C libft
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} $(LIBFT)
		${RM} $(BONUS_NAMEC)
		${RM} $(BONUS_NAMES)
		${RM} $(PRINTF)

re : fclean all

.PHONY:		all bonus clean fclean re