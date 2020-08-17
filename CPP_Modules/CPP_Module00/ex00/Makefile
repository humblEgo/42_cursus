NAME = megaphone
INCLUDES = -I.
CC = clang++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

MAIN_FILES = megaphone

SRCS_PATH = $(MAIN_FILES)
SRCS = $(addprefix ./, $(addsuffix .cpp, $(SRCS_PATH)))

OBJS = $(addsuffix .o, $(MAIN_FILES))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

${NAME}: ${OBJS}
	@echo "$(GREEN)Making START$(RESET)"
	@${CC} ${CFLAGS} ${INCLUDES} ${OBJS} -o ${NAME} -pthread
	@echo "$(GREEN)DONE"

${OBJS}: ${SRCS}
	@${CC} ${CFLAGS} ${INCLUDES} -c ${SRCS}

clean:
	@echo "$(RESET)Cleaning your object files$(RESET)"
	@${RM} $(OBJS)
	@echo "$(RED)clean DONE"

fclean: clean
	@echo "$(RESET)Removing program"
	@${RM} $(NAME)
	@echo "$(RED)fclean DONE"

re: fclean all

.PHONY:	all clean fclean re bonus
