#include "../include/fdf.h"

static int			length_size(char *line)
{
	int 	i;
	int 	length;

	i = 0;
	length = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] != ' ')
		{
			length++;
			while (line[i] != ' ' && line[i] != '\0')
				i++;
		}
		while (line[i] == ' ')
			i++;
	}
	return (length);
}

static void		get_width(char **line, char **argv, t_fdf *fdf)
{
	int fd;

	fdf->width = 0;
	fd = open(argv[1], O_RDONLY);
	while ((get_next_line(fd, line)) > 0)
	{
		fdf->width++;
		free(*line);
	}
	close(fd);
}

static void		get_length(char **line, char **argv, t_fdf *fdf)
{
	int 	fd;
	int 	x;

	x = 0;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);
	fdf->length = length_size(*line);
	free(*line);
	close(fd);
}

static void		fill_map(int *map, char **line)
{
	char		**str;
	int			i;

	i = 0;
	str = ft_strsplit(*line, ' ');
	while (str[i] != '\0')
	{
		map[i] = ft_atoi(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
}

static void		get_map(char **line, char **argv, t_fdf *fdf)
{
	int		x;
	int		y;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	fdf->map = (int**)malloc(sizeof(int*) * (fdf->width + 1));
	while (i < fdf->width)
		fdf->map[i++] = (int*)malloc(sizeof(int) * fdf->length);
	i = 0;
	while (get_next_line(fd, line))
	{
		fill_map(fdf->map[i], line);
		free(*line);
		i++;
	}
	close(fd);
	fdf->map[i] = NULL;
}

int			main(int argc, char **argv)
{
	int		fd;
	char 	*line;
	t_fdf	*fdf;
	int i;
	int j;

	i = 0;
	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	get_length(&line, argv, fdf);
	get_width(&line, argv, fdf);
	get_map(&line, argv, fdf);
	while (i < fdf->width)
	{
		j = 0;
		while (j < fdf->length)
		{
			ft_printf("%3d", fdf->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	free(fdf);
	return (0);
}