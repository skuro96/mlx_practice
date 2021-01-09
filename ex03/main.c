#include <stdio.h>
#include <mlx.h>

typedef struct	s_vars
{
	void *mlx;
	void *win;
}				t_vars;

int key_hook(void)
{
	return printf("a\n");
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 320, 200, "ex03");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
