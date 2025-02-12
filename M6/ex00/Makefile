# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 15:31:59 by shaboom           #+#    #+#              #
#    Updated: 2025/02/11 15:49:02 by araveala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TEST_DIR = tests
SRC_DIR = src
INCS = incs
CPPFILES = 	$(SRC_DIR)/converterUtils.cpp\
			$(SRC_DIR)/main.cpp\
			$(SRC_DIR)/ScalarConverter.cpp
			
HPPFILES = 	$(INCS)/converterUtils.hpp\
			$(INCS)/ScalarConverter.hpp
CPP = c++
CPPFLAGS = -I$(SRC_DIR) -I$(INCS) -Werror -Wextra -Wall -Wshadow -std=c++11 -MMD -MP

BUILDDIR = buildofiles/
OFILES = $(addprefix $(BUILDDIR), $(notdir $(CPPFILES:.cpp=.o)))
DEPFILES = $(OFILES:.o=.d)
NAME = convert


all: $(BUILDDIR) $(NAME)

$(BUILDDIR)%.o: $(SRC_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -g -c $< -o $@

$(NAME): $(BUILDDIR) $(OFILES)
	$(CPP) $(CPPFLAGS) $(OFILES) -o $(NAME)
	@echo "\033[0;95m Created executable\033[0m"

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	@echo "\033[0;91m Build folder created\033[0m"

-include $(DEPFILES)

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(OFILES)
	rm -rf $(DEPFILES)
	@echo "\033[0;93m build directory, ofiles and depency files cleaned out\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[0;91m executbale removed\033[0m"

re: fclean all $(NAME)

.PHONY: all clean fclean re