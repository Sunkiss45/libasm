NAME = libasm.a
NAMEB = libasm_bonus.a

EXE = testage_libasm

LIB = ar rcs
ASM = nasm
ASMFLAGS = -f elf64
INC = -Iincludes

CC = clang
CCFLAGS = -Wall -Wextra -Werror -fno-builtin
SAN = -fsanitize=address -g3 -fomit-frame-pointer
RUN = -fomit-frame-pointer

SRCS =  srcs/ft_strlen.s \
			srcs/ft_strcpy.s \
			srcs/ft_strcmp.s \
			srcs/ft_write.s \
			srcs/ft_read.s \
			srcs/ft_strdup.s \

OBJS = $(SRCS:%.s=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

%.o: %.s
	$(ASM) $(ASMFLAGS) -o $@ $< $(INC)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)

fclean: clean
	rm -rf $(NAME) $(NAMEB) $(EXE) testage_file.txt

re: fclean all

SRCS_B =  srcs_bonus/ft_atoi_base_bonus.s \

OBJS_B = $(SRCS_B:%.s=%.o)

bonus: $(NAMEB)

$(NAMEB): $(OBJS_B)
	$(LIB) $(NAMEB) $(OBJS_B)

# ====== #
# CUSTOM #
# ====== #

run: re
	$(CC) $(CCFLAGS) $(RUN) main.c -o $(EXE) $(NAME)
	touch testage_file.txt

san: re
	$(CC) $(CCFLAGS) $(SAN) main.c -o $(EXE) $(NAME)
	touch testage_file.txt

.PHONY: all clean fclean re run san