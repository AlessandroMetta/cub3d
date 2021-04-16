#include "../cub3d.h"
#define BUFFER_SIZE 1
#define MAX_OPEN 256

// GNL according to the norm V3

int	ft_strjoin_checker(char **dest, char **s1, char **s2)
{
	*dest = ft_strjoin(*s1, *s2);
	free(*s1);
	free(*s2);
	if (!*dest)
		return (-1);
	return (0);
}

int	ft_strdup_checker(char **line, const char *to_alloc)
{
	*line = ft_strdup(to_alloc);
	if (!*line)
		return (-1);
	return (0);
}

int	ft_read_line(char **p_el, char **rescue, int fd)
{
	char	*line_red;
	char	*temp;
	int		return_value;

	return_value = BUFFER_SIZE;
	*p_el = ft_strchr(*rescue, '\n');
	while (!*p_el && return_value == BUFFER_SIZE)
	{
		line_red = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!line_red)
			return (-1);
		return_value = read(fd, line_red, BUFFER_SIZE);
		if (return_value < 0)
		{
			free(line_red);
			return (-1);
		}
		line_red[return_value] = '\0';
		if (ft_strjoin_checker(&temp, rescue, &line_red) == -1)
			return (-1);
		*rescue = temp;
		*p_el = ft_strchr(*rescue, '\n');
	}
	return (return_value);
}

int	ft_return(char **p_el, char **rescue)
{
	char	*temp;

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

int	get_next_line(int fd, char **line)
{
	static char		*rescue[MAX_OPEN];
	char			*p_el;

	if (fd < 0 || fd > MAX_OPEN || !line || BUFFER_SIZE <= 0)
		return (-1);
	p_el = NULL;
	if (!rescue[fd])
		if (ft_strdup_checker(&rescue[fd], ""))
			return (-1);
	if ((ft_read_line(&p_el, &rescue[fd], fd)) < 0)
	{
		free(rescue[fd]);
		return (-1);
	}
	if (p_el)
		*p_el = '\0';
	if (ft_strdup_checker(line, rescue[fd]))
	{
		free(rescue[fd]);
		return (-1);
	}
	return (ft_return(&p_el, &rescue[fd]));
}
