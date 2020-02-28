#ifndef VISUAL_H
# define VISUAL_H
# include <ncurses.h>
# include "vm.h"

# define COLOR_P1	1
# define COLOR_P2	2
# define COLOR_P3	3
# define COLOR_P4	4

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
t_visu	*init_visu(void);
void	init_colors(void);
void	init_player(t_visu *visu, char *p1, char *p2, char *p3, char *p4);
void	init_arena(t_visu *visu);
#endif