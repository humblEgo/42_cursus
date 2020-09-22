NAME = container_tests 
INCLUDES = -I include -I include/utils -I tests
CC = clang++
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MAIN_FILES = main container_test vector_test list_test stack_test SampleClass

SRCS_PATH = $(MAIN_FILES)
VPATH := .:srcs:tests
SRCS = $(addsuffix .cpp, $(SRCS_PATH))

OBJDIR = ./objs
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(MAIN_FILES)))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

${NAME}: ${OBJS}
	@echo "$(GREEN)Making START$(RESET)"
	@${CC} ${CFLAGS} ${INCLUDES} ${OBJS} -o ${NAME}
	@echo "$(GREEN)DONE"

$(OBJDIR)/%.o : %.cpp
	@mkdir -p $(OBJDIR)
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	@echo "$(RESET)Cleaning your object files$(RESET)"
	@${RM} $(OBJDIR) 
	@echo "$(RED)clean DONE"

fclean: clean
	@echo "$(RESET)Removing program"
	@${RM} $(NAME)
	@echo "$(RED)fclean DONE"

re: fclean all

.PHONY:	all clean fclean re bonus
