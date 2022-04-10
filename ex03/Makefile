#############
# Functions #
#############

uniq = $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1)))

#############
# Variables #
#############

# TODO: fill in here
NAME	:= a.out
SRCS	:= main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
TEST_CPP:=

CXX		:= c++
CXXFLAGS:= -g -Wall -Werror -Wextra -std=c++98

SRCDIRS	:= $(call uniq, $(dir $(SRCS)))

OBJDIR	:= build/
OBJDIRS	:= $(addprefix $(OBJDIR), $(SRCDIRS))
OBJS	:= $(addprefix $(OBJDIR), $(SRCS:%.cpp=%.o))

DEPS	:= $(addprefix $(OBJDIR), $(SRCS:%.cpp=%.d))

DSTRCTR	:= ./destructor.c

#################
# General rules #
#################

all: $(NAME)

$(NAME): $(OBJDIRS) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LIBS)

clean: FORCE
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(NAME).dSYM

re: fclean all

run: $(NAME)
	./$(NAME)

norm: FORCE
	@printf "$(RED)"; norminette | grep -v ": OK!" \
	&& exit 1 \
	|| printf "$(GREEN)%s\n$(END)" "Norm OK!"

$(OBJDIRS):
	mkdir -p $@

$(OBJDIR)%.o: %.cpp
	@printf "$(THIN)$(ITALIC)"
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@
	@printf "$(END)"

-include $(DEPS)

.PHONY: FORCE
FORCE:

###############
# Debug rules #
###############

$(DSTRCTR):
	curl https://gist.githubusercontent.com/ywake/793a72da8cdae02f093c02fc4d5dc874/raw/destructor.c > $(DSTRCTR)

sani: $(OBJDIRS) $(OBJS)
	$(CXX) $(CXXFLAGS) -fsanitize=address $(OBJS) -o $(NAME) $(LIBS)

Darwin_leak: $(DSTRCTR) $(OBJDIRS) $(OBJS)
	$(CXX) -g $(OBJS) $(DSTRCTR) -o $(NAME) $(LIBS)

Linux_leak: sani

leak: $(shell uname)_leak

##############
# Test rules #
##############

test: all
	./$(NAME)

##########
# Colors #
##########

END		= \e[0m
BOLD	= \e[1m
THIN	= \e[2m
ITALIC	= \e[3m
U_LINE	= \e[4m
BLACK	= \e[30m
RED		= \e[31m
GREEN	= \e[32m
YELLOW	= \e[33m
BLUE	= \e[34m
PURPLE	= \e[35m
CYAN	= \e[36m
WHITE	= \e[37m
