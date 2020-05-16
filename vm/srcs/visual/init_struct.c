#include "vm.h"

t_win	*ft_struct_arena(void)
{
	t_win	*arena;

	arena = (t_win *)malloc(sizeof(t_win));
	if (arena == NULL)
		return (NULL);
	arena->dim.lines = 67;
	arena->dim.cols = 203;
	arena->coord.x = 0;
	arena->coord.y = 0;
	return (arena);
}

t_win	*ft_struct_info(void)
{
	t_win	*info;

	info = (t_win *)malloc(sizeof(t_win));
	if (info == NULL)
		return (NULL);
	info->dim.lines = 67;
	info->dim.cols = 60;
	info->coord.x = 203;
	info->coord.y = 0;
	return (info);
}