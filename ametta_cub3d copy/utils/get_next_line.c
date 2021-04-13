#include "cub3d.h"
#include <unistd.h>
#include "libft/libft.h"
#define BUFFER_SIZE 1
#define MAX_OPEN 256

static int	ft_reading(char **n_l, char **save, int fd)
{
	int		red;
	char	*buffer;
	char	*temp;

	red = BUFFER_SIZE;
	while (!(*n_l = ft_strchr(save[fd], '\n')) && (red == BUFFER_SIZE))
	{
		if (!(buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char))))
		{
			free(save[fd]);
			return (-1);
		}
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
		{
			free(save[fd]);
			free(buffer);
			return (-1);
		}
		temp = ft_strjoin(save[fd], buffer);
		free(save[fd]);
		save[fd] = temp;
		free(buffer);
	}
	return (0);
}

static int	ft_return(char **p_el, char **rescue)
{
	char *temp;

	if (*p_el)
	{
		temp = ft_strdup(*p_el + 1);
		if (!temp)
		{
			free(*rescue);
			return (-1);
		}
		free(*rescue);
		*rescue = temp;
		return (1);
	}
	free(*rescue);
	*rescue = NULL;
	return (0);
}

static int	ft_memleak(char **line)
{
	if (!line)
	{
		line = (char *)ft_calloc(sizeof(char), 1);
		if (!line)
			return (-1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char *save[MAX_OPEN];
	char		*n_l;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || fd > MAX_OPEN)
		return (-1);
	n_l = 0;
	if (ft_memleak(&save[fd]) == -1)
		return (-1);
	if (ft_reading(&n_l, save, fd) != 0)
	{
		free(save[fd]);
		return (-1);
	}
	if (n_l)
		*n_l = 0;
	*line = ft_strdup(save[fd]);
	if (!line)
	{
		free(save[fd]);
		return (-1);
	}
	return (ft_return(&n_l, &save[fd]));
}
