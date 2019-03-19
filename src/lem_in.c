/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 10:40:19 by pmartyny          #+#    #+#             */
/*   Updated: 2019/02/27 10:40:21 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		convert_line(t_anthill **t_str, t_input **t_in, char *line)
{
	if (ft_strchr(line, '#') && ft_strcmp(line, "##start") != 0 &&
		ft_strcmp(line, "##end") != 0)
	{
		if (line[0] == '#')
			return (1);
	}
	else if (ft_strcmp(line, "##start") == 0)
	{
		if (read_start(t_str, t_in) == 0)
			return (0);
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (read_end(t_str, t_in) == 0)
			return (0);
	}
	else
		return (convert_line_2(t_str, line));
	return (1);
}

int		convert_line_2(t_anthill **t_str, char *line)
{
	if (ft_strchr(line, '-'))
	{
		if (read_conection(t_str, line) == 0)
			return (0);
	}
	else if (ft_strchr(line, ' '))
	{
		if (read_room(line, t_str) == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

int		read_input(t_anthill **t_str, t_input **t_in, t_path ***path, int flag)
{
	char		*line;
	int			read;

	line = NULL;
	if (read_ant_number(t_in) == 0)
		return (0);
	while ((read = get_next_line(0, &line)))
	{
		if (read <= 0)
			return (0);
		add_input_line(t_in, line);
		if (convert_line(t_str, t_in, line) == 0)
			return (0);
	}
	parse_flag(t_str, t_in, path, flag);
	return (1);
}

void	parse_flag(t_anthill **t_str, t_input **t_in, t_path ***path, int flag)
{
	int		num;

	num = 0;
	if (flag == 0)
	{
		print_input(t_in);
		ft_printf("\n");
		if (find_path(t_str, path) == 1)
			move_ants(path);
	}
	else if (flag == 1)
		print_input(t_in);
	else if (flag == 2)
	{
		if (find_path(t_str, path) == 1)
			move_ants(path);
		num = lines_need(t_in);
		ft_printf("Required number of lines: %d\n", num);
		ft_printf("My number of lines:       %d\n", g_line_number);
	}
}

int		main(int argc, char **argv)
{
	t_path		**path;
	t_anthill	*t_str;
	t_input		*t_in;
	int			flag;

	g_ant_number = 0;
	g_line_number = 0;
	t_str = NULL;
	t_in = NULL;
	flag = INT_MAX;
	if (argc == 1)
		flag = 0;
	else if (ft_strcmp(argv[1], "-i") == 0)
		flag = 1;
	else if (ft_strcmp(argv[1], "-r") == 0)
		flag = 2;
	else if (ft_strcmp(argv[1], "-help") == 0)
	{
		write_usage();
		return (0);
	}
	if (read_input(&t_str, &t_in, &path, flag) == 0)
		ft_printf("ERROR\n");
	return (0);
}
