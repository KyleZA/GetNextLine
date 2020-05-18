#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# define FD_SIZE 4096

# include <fcntl.h>
# include "libft/libft.h"

int				get_next_line(int const fd, char **line);

#endif
