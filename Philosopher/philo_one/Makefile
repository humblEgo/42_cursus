NAME = philo_one
INCLUDES = -I./include/
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

MAIN_FILES = main 

SRCS_PATH = $(MAIN_FILES)
SRCS = $(addprefix srcs/, $(addsuffix .c, $(SRCS_PATH)))

OBJS = $(addsuffix .o, $(MAIN_FILES))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

${NAME}: ${OBJS}
	@echo "$(GREEN)MONGSHELL START$(RESET)"
	@make -C ${LIB_DIR}
	@echo "$(RESET)Copying ${LIBLARY} to root."
	@cp ${LIB_DIR}${LIBLARY} .
	@echo "$(RESET)Compiling ${NAME} to root."
	@${CC} ${CFLAGS} ${INCLUDES} -lft -L. ${OBJS} -o ${NAME}
	@echo "$(GREEN)DONE"

${OBJS}: ${SRCS}
	@${CC} ${CFLAGS} ${INCLUDES} -c ${SRCS}

clean:
	@echo "$(RESET)Cleaning your mongshell .o files$(RESET)"
	@${RM} $(OBJS)
	@echo "Cleaning your libft files"
	@make -C libft/ fclean
	@${RM} ${LIBLARY}
	@echo "$(RED)clean DONE"

fclean: clean
	@echo "$(RESET)Removing mongshell"
	@${RM} $(NAME)
	@echo "$(RED)fclean DONE"

re: fclean all

.PHONY:	all clean fclean re bonus