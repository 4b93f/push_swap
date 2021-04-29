PS_SRCS =		srcs/push_swap.c srcs/ft_struct_ps.c srcs/ft_engine.c srcs/stack/stack_utils.c srcs/stack/stack_utils_bis.c srcs/instructions/instructions_a.c \
				srcs/ft_engine_bis.c srcs/instructions/instructions_b.c srcs/ft_verif.c srcs/ft_error.c srcs/utils.c
CH_SRCS =		srcs/checker.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c srcs/stack/stack_utils.c  srcs/ft_error.c srcs/ft_verif.c \
				srcs/stack/stack_utils_bis.c srcs/ft_struct_ps.c srcs/instructions/checker_instructions_a.c srcs/instructions/checker_instructions_b.c srcs/utils.c

PS_HEADERS =	push_swap.h
CH_HEADERS = 	checker.h

PS_NAME = 		push_swap
CH_NAME =		checker

PS_OBJ = 		${PS_SRCS:.c=.o}
CH_OBJ =		$(CH_SRCS:.c=.o)

FLAGS =			-Wall -Wextra -Werror
LIB = ./libft/libft.a

%.o: %.c
				@gcc -c -g3 -o $@ $?

$(PS_NAME): ${PS_OBJ} $(CH_NAME)
				@gcc -g3 ${FLAGS} ${PS_OBJ} ${LIB} -o ${PS_NAME}
				@echo "[Done !]"

$(CH_NAME): $(CH_OBJ)
				@echo "[Libft compilation...]"
				@$(MAKE) -C ./libft		
				@$(MAKE) bonus -C ./libft
				@gcc -g3 ${FLAGS} $(CH_OBJ) ${LIB} -o $(CH_NAME)

all:	${PS_NAME} $(CH_NAME)

clean:	
				@echo "Cleaning..."
				@/bin/rm -f ${PS_OBJ} ${CH_OBJ} 
				@rm -f ${PS_NAME} $(CH_NAME) 
				@echo "Cleaning complete!"

fclean:			clean
				@rm -f

re:				fclean all


.PHONY :		fclean all re clean