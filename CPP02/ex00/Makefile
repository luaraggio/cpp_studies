NAME = ex00

CC = c++

C_FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =		main.cpp \
			Fixed.cpp

RESET =		\033[0m
PINK =		\033[0;35m
BLUE =		\033[0;34m

OBJS =		${SRCS:.cpp=.o}

.cpp.o:
			$(CC) $(C_FLAGS) -c $< -o $@

all:		$(NAME)
			@echo "$(PINK)$(NAME) is ready!$(RESET)"

$(NAME):	$(OBJS)
			@$(CC) $(C_FLAGS) $(SRCS) -o $(NAME)

clean:
			@rm -f $(OBJS)
			@echo "$(BLUE) 📤 Objects deleted$(RESET)"

fclean:
			@rm -f $(NAME)
			@rm -f $(OBJS)
			@echo "$(BLUE) 🧼 All cleaned$(RESET)"

re:			fclean all

run:		re
			./$(NAME)

val:		re
			valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)
