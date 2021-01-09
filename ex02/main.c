#include <mlx.h>

int g_win_width = 320;
int g_win_height = 200;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void put_rect(t_data *data, int sx, int sy, int ex, int ey, int color)
{
	int i;
	int j;

	i = sy;
	while (i < ey)
	{
		j = sx;
		while (j < ex)
		{
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, g_win_width, g_win_height, "ex02");
	img.img = mlx_new_image(mlx, g_win_width, g_win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	put_rect(&img, g_win_width / 4, g_win_height / 4, g_win_width * 3 / 4, g_win_height * 3 / 4, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
