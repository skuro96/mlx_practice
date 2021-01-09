#include <stdio.h>
#include <mlx.h>

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef struct	s_vars
{
	void *mlx;
	void *win;
}				t_vars;

int key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == KEY_ESC)
		printf("ESC\n");
	else if (keycode == KEY_W)
		printf("W\n");
	else if (keycode == KEY_A)
		printf("A\n");
	else if (keycode == KEY_S)
		printf("S\n");
	else if (keycode == KEY_D)
		printf("D\n");
	return (1);
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 320, 200, "ex04");
	mlx_key_hook(vars.win, &key_hook, &vars);
	mlx_loop(vars.mlx);
}
