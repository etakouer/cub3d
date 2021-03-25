SRCS		=	main.c \
				main_utils.c \
				parser/ft_parser.c \
			 	parser/get_next_line.c \
			 	parser/get_next_line_utils.c \
				parser/ft_parser_config.c \
				parser/ft_parser_config_utils.c \
				parser/ft_parser_config_utils1.c \
				parser/ft_parser_map.c \
			 	raycast/ft_raycast.c \
				raycast/ft_draw.c \
			 	raycast/ft_mlx_puts.c \
				raycast/ft_mlx_puts_basics.c \
				raycast/ft_mlx_puts_utils.c \
				raycast/ft_mlx_hooks.c \
				raycast/ft_raysprite_utils.c \
				raycast/ft_raycast_utils.c \
				raycast/ft_raytxt.c \
				raycast/ft_raysprite.c \
				raycast/ft_rayxy.c \
				raycast/ft_save.c \
				utils/ft_memcpy.c \
				utils/ft_error.c \
				utils/ft_strcmp.c \
				utils/ft_strlen.c \
				utils/ft_free.c \
				utils/ft_math.c \
				utils/ft_debug_map.c \
				utils/ft_split.c \
				utils/ft_atoi.c \
				utils/ft_strdup.c \
				utils/ft_isdigit.c

OBJS		= ${SRCS:.c=.o}

BONUS_OBJS	= $(BONUS:.c=.o)

NAME		= cub3D

CFLAGS		= -Wall -Wextra -Werror

LIBS		= -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all:		${NAME}

$(NAME):	$(OBJS)
			gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

bonus :		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			rm -f $(NAME) 

re:			fclean all

s:			clean all

.PHONY:		all clean fclean re
