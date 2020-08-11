NAME = philo_two
INCLUDES = -I./include/
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

MAIN_FILES = main ft_atoi print_ph_state utils init_ph_info init_cond_forks_ph \
			routine_ph_actions monitor error clean create_detached_thread \
			unlink_semaphores semaphore

SRCS_PATH = $(MAIN_FILES)
SRCS = $(addprefix srcs/, $(addsuffix .c, $(SRCS_PATH)))

OBJS = $(addsuffix .o, $(MAIN_FILES))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

${NAME}: ${OBJS}
	@echo "$(GREEN)PHIOLOSOPHY START$(RESET)"
	@${CC} ${CFLAGS} ${INCLUDES} ${OBJS} -o ${NAME} -lpthread
	@echo "$(GREEN)DONE"

${OBJS}: ${SRCS}
	@${CC} ${CFLAGS} ${INCLUDES} -c ${SRCS}

clean:
	@echo "$(RESET)Cleaning your mongshell .o files$(RESET)"
	@${RM} $(OBJS)
	@echo "$(RED)clean DONE"

fclean: clean
	@echo "$(RESET)Removing mongshell"
	@${RM} $(NAME)
	@echo "$(RED)fclean DONE"

re: fclean all

.PHONY:	all clean fclean re bonus
