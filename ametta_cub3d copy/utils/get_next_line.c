#include "../cub3d.h"
#define BUFFER_SIZE 1
#define MAX_OPEN 256

int	ft_rl_light(char **temp, char **rescue, char **line_red)
{
	*temp = ft_strjoin(*rescue, *line_red);
	if (!*temp)
	{
		free(*line_red);
		return (-1);
	}
	return (0);
}

int	ft_read_line(char **p_el, char **rescue, int fd, int buff_size)
{
	char	*line_red;
	char	*temp;
	int		return_value;

	return_value = buff_size;
	while (!(*p_el = ft_strchr(*rescue, '\n')) && return_value == buff_size)
	{
		line_red = (char *)malloc(sizeof(char) * (buff_size + 1));
		if (!line_red)
			return (-1);
		return_value = read(fd, line_red, buff_size);
		if (return_value < 0)
		{
			free(line_red);
			return (-1);
		}
		line_red[return_value] = '\0';
		if (ft_rl_light(&temp, rescue, &line_red) == -1)
			return (-1);
		free(*rescue);
		free(line_red);
		*rescue = temp;
	}
	return (return_value);
}

int	ft_return(char **p_el, char **rescue)
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

int	get_next_line(int fd, char **line)
{
	static char		*rescue[MAX_OPEN];
	char			*p_el;

	if (fd < 0 || fd > MAX_OPEN || !line || BUFFER_SIZE <= 0)
		return (-1);
	p_el = NULL;
	if (!(rescue[fd]))
	{
		rescue[fd] = ft_strdup("");
		if (!rescue[fd])
			return (-1);
	}
	if ((ft_read_line(&p_el, &rescue[fd], fd, BUFFER_SIZE)) < 0)
	{
		free(rescue[fd]);
		return (-1);
	}
	if (p_el)
		*p_el = '\0';
	*line = ft_strdup(rescue[fd]);
	if (!(*line))
	{
		free(rescue[fd]);
		return (-1);
	}
	return (ft_return(&p_el, &rescue[fd]));
}