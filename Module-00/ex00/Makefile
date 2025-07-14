SRC = megaphone.cpp
CPPC = c++ -std=c++98
CPPFLAGS = -Wall -Wextra -Werror
NAME = megaphone
OBJ = $(SRC:.cpp=.opp)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;32m✅ Compiling complete source code into executable...\033[0m"
	@$(CPPC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[1;32m🎉 Build successful! You can now run ./megaphone\033[0m"

%.opp: %.cpp
	@$(CPPC) $(CPPFLAGS) -c $< -o $@
	@echo "\033[1;34m🔹 Compiling: $< -> $@\033[0m"

clean:
	@echo "\033[0;33m🧼 Removing compiled object files to clean up...\033[0m"
	@rm -f $(OBJ)
	@echo "\033[0;32m✔️  Clean complete.\033[0m"

fclean: clean
	@echo "\033[0;31m🗑️ Removing final executable (megaphone)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[0;32m✔️  Full clean complete.\033[0m"

re: fclean all


