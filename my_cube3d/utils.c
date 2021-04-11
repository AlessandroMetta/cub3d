#include "cube3d.h"

int ft_jump_space(char **str)
{
	while (*str && ft_strchr(" \t\v\f\r", **str))
		*str += 1;
	return 0;
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	init_struct_specs(t_specs *map)
{
	map->path = 0;
	map->save = 0;
	map->width = 0;
	map->height = 0;
	map->no_t = 0;
	map->so_t = 0;
	map->ea_t = 0;
	map->we_t = 0;
	map->sp_t = 0;
	map->f_c = 0;
	map->c_c = 0;
}

void	debug_struct_specs(t_specs map)
{
	printf("	--	DEBUGGING PROCESS	--\n");
	printf("width:			%d\nheight:			%d\n", map.width, map.height);
	printf("north textrure path:	%s\n", map.no_t);
	printf("south textrure path:	%s\n", map.so_t);
	printf("east textrure path:	%s\n", map.ea_t);
	printf("west textrure path:	%s\n", map.we_t);
	printf("sprite textrure path:	%s\n", map.sp_t);
	printf("floor color: 		%d\n", map.f_c);
	printf("ceiling color:		%d\n", map.c_c);
	printf("save opt:		%d\n", map.save);
	printf("\n		map debug\n");
	print_mat(map.map);
}

int 	map_moment(t_specs *map)
{
	if (map->width && map->height && map->no_t && map->so_t &&
		map->ea_t && map->we_t && map->sp_t && map->f_c && map->c_c)
		return (1);
	return (0);
}

int		ft_strrstr(char *haystack, char *needle)
{
	int hlen;
	int nlen;

	hlen = ft_strlen(haystack);
	nlen = ft_strlen(needle);
	while (nlen > 0)
	{
		if(needle[--nlen] != haystack[--hlen])
			return (0);
	}
	return (1);
}