NAME = libasm.a

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

san: re
	$(CC) $(CCFLAGS) $(SAN) main.c -o testage_libasm $(NAME)
	touch testage_file.txt

run: re
	$(CC) $(CCFLAGS) $(RUN) main.c -o testage_libasm $(NAME)
	touch testage_file.txt

%.o: %.s
	$(ASM) $(ASMFLAGS) -o $@ $< $(INC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) testage_libasm testage_file.txt

re: fclean all

# .PHONY: all san clean fclean re
.PHONY: all san clean fclean re