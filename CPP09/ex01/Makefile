NAME = RPN

CC = c++

C_FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =		main.cpp \
			RPN.cpp

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

test: all
	@echo "$(PINK)============= RPN TESTS =============$(RESET)"
	@echo

	@echo "[TEST 1] ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\""
	@sleep 0.8
	@echo "Running..."
	@sleep 0.8
	@out=$$(./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" 2>&1); \
	echo "$$out"; \
	if [ "$$out" = "42" ]; then \
		echo "Result: $$out ✅ OK"; \
	else \
		echo "Result: $$out ❌ KO (expected: 42)"; \
	fi
	@echo "✔ Done"
	@echo
	@sleep 0.8

	@echo "[TEST 2] ./RPN \"7 7 * 7 -\""
	@sleep 0.8
	@echo "Running..."
	@sleep 0.8
	@out=$$(./RPN "7 7 * 7 -" 2>&1); \
	echo "$$out"; \
	if [ "$$out" = "42" ]; then \
		echo "Result: $$out ✅ OK"; \
	else \
		echo "Result: $$out ❌ KO (expected: 42)"; \
	fi
	@echo "✔ Done"
	@echo
	@sleep 0.8

	@echo "[TEST 3] ./RPN \"1 2 * 2 / 2 * 2 4 - +\""
	@sleep 0.8
	@echo "Running..."
	@sleep 0.8
	@out=$$(./RPN "1 2 * 2 / 2 * 2 4 - +" 2>&1); \
	echo "$$out"; \
	if [ "$$out" = "0" ]; then \
		echo "Result: $$out ✅ OK"; \
	else \
		echo "Result: $$out ❌ KO (expected: 0)"; \
	fi
	@echo "✔ Done"
	@echo
	@sleep 0.8

	@echo "[TEST 4] ./RPN \"(1 + 1)\""
	@sleep 0.8
	@echo "Running..."
	@sleep 0.8
	@out=$$(./RPN "(1 + 1)" 2>&1); \
	echo "$$out"; \
	if echo "$$out" | grep -q "Error"; then \
		echo "Result: Error ✅ OK"; \
	else \
		echo "Result: $$out ❌ KO (expected: Error)"; \
	fi
	@echo "✔ Done"
	@echo
	@sleep 0.8

	@echo "$(PINK)=========== END OF TESTS ===========$(RESET)"

val:		re
			valgrind  --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: test
