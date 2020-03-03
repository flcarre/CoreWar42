#ifndef VISUAL_H
# define VISUAL_H
# include <stdlib.h>
// # include "vm.h"

# define COLOR_DEF	0
# define COLOR_P1	1
# define COLOR_P2	2
# define COLOR_P3	3
# define COLOR_P4	4
# define COLOR_P5	5
# define COLOR_P6	6
# define COLOR_P7	7

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;
typedef struct	s_dim
{
	int	lines;
	int	cols;
}				t_dim;
typedef struct	s_win
{
	t_coord	coord;
	t_dim	dim;
	WINDOW	*window;
}				t_win;

typedef struct	s_visu
{
	t_win	*arena;
	t_win	*info;
}				t_visu;
#endif