# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 11:11:54 by shaboom           #+#    #+#              #
#    Updated: 2025/04/16 15:02:13 by araveala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPPFILES = main.cpp Span.cpp
CPP = c++
CPPFLAGS = -Werror -Wextra -Wall -Wshadow -Wno-shadow -std=c++17 -MMD -MP
BUILDDIR = buildofiles/
OFILES = $(addprefix $(BUILDDIR), $(CPPFILES:.cpp=.o))
DEPFILES = $(OFILES:.o=.d)
NAME = span

all: $(BUILDDIR) $(NAME)

$(BUILDDIR)%.o: %.cpp
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