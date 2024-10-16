#include "so_long.h"

char	*quick_read_map(int fd)
{
	char	*str;
	char	*str_cpy;
	int		rd;
	char	buf[2];

	rd = read(fd, buf, 1);
	buf[1] = 0;
	str = ft_strdup(buf);
	while (rd)
	{
		if (!str)
			return (NULL);
		rd = read(fd, buf, 1);
		buf[1] = 0;
		if (!rd)
			break ;
		str_cpy = str;
		str = ft_strjoin(str_cpy, buf);
		free(str_cpy);
		str_cpy = NULL;
	}
	return (str);
}

