PS_SRCS =		push_swap.c ft_struct_ps.c ft_engine.c
CH_SRCS =		checker.c

PS_HEADERS =	push_swap.h
CH_HEADERS = 	checker.h

PS_NAME = 		push_swap
CH_NAME =		checker

PS_OBJ = 		${PS_SRCS:.c=.o}
CH_OBJ =		$(CH_SRCS:.c=.o)

FLAGS =			-Wall -Wextra -Werror
LIB = ./libft/libft.a

%.o: %.c
				@gcc -c -o $@ $?

$(PS_NAME): ${PS_OBJ} $(CH_NAME)
				@echo "[Libft compilation...]"
				@$(MAKE) -C libft/
				@$(MAKE) bonus -C libft/
				@gcc -g3 ${FLAGS} ${PS_OBJ} ${LIB} -o ${PS_NAME}

$(CH_NAME): $(CH_OBJ)
				@gcc -g3 ${FLAGS} $(CH_OBJ) ${LIB} -o $(CH_NAME)
				echo "[Done !]"

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