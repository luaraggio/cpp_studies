NAME = PmergeMe

CC = c++

C_FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =		main.cpp \
			PmergeMe.cpp

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
			@rm -f *_shrubbery
			@echo "$(BLUE) 🧼 All cleaned$(RESET)"

re:			fclean all

run:		re
			./$(NAME)

test_mac: all
	@echo "$(PINK)=========== PMERGEME TESTS (macOS) ===========$(RESET)"
	@echo

	@echo "[TEST 1] Small input"
	@echo "./PmergeMe 3 5 9 7 4"
	@sleep 0.5
	@out=$$(./PmergeMe 3 5 9 7 4 2>&1); \
	echo "$$out"; \
	echo "$$out" | grep -q "After: 3 4 5 7 9" && \
	echo "$(GREEN)Result: OK ✅$(RESET)" || \
	echo "$(RED)Result: KO ❌$(RESET)"

	@echo
	@echo "[TEST 2] Large input (jot)"
	@echo "./PmergeMe \$$(jot -r 3000 1 100000)"
	@sleep 0.5
	@out=$$(./PmergeMe $$(jot -r 3000 1 100000) 2>&1); \
	echo "$$out" | head -n 5; \
	echo "$$out" | grep -q "Time to process a range of 3000 elements" && \
	echo "$(GREEN)Result: OK ✅$(RESET)" || \
	echo "$(RED)Result: KO ❌$(RESET)"

	@echo
	@echo "[TEST 3] Error handling"
	@echo "./PmergeMe -1 2"
	@sleep 0.5
	@out=$$(./PmergeMe -1 2 2>&1); \
	echo "$$out"; \
	if [ "$$out" = "Error" ] || echo "$$out" | grep -q "^Error"; then \
		echo "$(GREEN)Result: OK ✅$(RESET)"; \
	else \
		echo "$(RED)Result: KO ❌$(RESET)"; \
	fi

	@echo
	@echo "$(PINK)========= END OF TESTS (macOS) =========$(RESET)"

test_linux: all
	@echo "$(PINK)=========== PMERGEME TESTS (Linux) ===========$(RESET)"
	@echo

	@echo "[TEST 1] Small input"
	@echo "./PmergeMe 3 5 9 7 4"
	@sleep 0.5
	@out=$$(./PmergeMe 3 5 9 7 4 2>&1); \
	echo "$$out"; \
	echo "$$out" | grep -q "After: 3 4 5 7 9" && \
	echo "$(GREEN)Result: OK ✅$(RESET)" || \
	echo "$(RED)Result: KO ❌$(RESET)"

	@echo
	@echo "[TEST 2] Large input (shuf)"
	@echo "./PmergeMe \$$(shuf -i 1-100000 -n 3000)"
	@sleep 0.5
	@out=$$(./PmergeMe $$(shuf -i 1-100000 -n 3000) 2>&1); \
	echo "$$out" | head -n 5; \
	echo "$$out" | grep -q "Time to process a range of 3000 elements" && \
	echo "$(GREEN)Result: OK ✅$(RESET)" || \
	echo "$(RED)Result: KO ❌$(RESET)"

	@echo
	@echo "[TEST 3] Error handling"
	@echo "./PmergeMe -1 2"
	@sleep 0.5
	@out=$$(./PmergeMe -1 2 2>&1); \
	echo "$$out"; \
	if [ "$$out" = "Error" ] || echo "$$out" | grep -q "^Error"; then \
		echo "$(GREEN)Result: OK ✅$(RESET)"; \
	else \
		echo "$(RED)Result: KO ❌$(RESET)"; \
	fi

	@echo
	@echo "$(PINK)========= END OF TESTS (Linux) =========$(RESET)"

val:		re
			valgrind  --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: test
