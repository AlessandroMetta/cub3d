#include "cub3d.h"

int	ft_strrstr(char *haystack, char *needle)
{
	int	hlen;
	int	nlen;

	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	while (nlen > 0)
	{
		if (needle[--nlen] != haystack[--hlen])
			return (0);
	}
	return (1);
}
