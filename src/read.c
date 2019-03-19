/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 10:54:00 by pmartyny          #+#    #+#             */
/*   Updated: 2019/02/27 10:54:01 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		read_ant_number(t_input **t_in)
{
	char	*line;
	int		i;
	int		read;

	i = -1;
	line = NULL;
	while ((read = get_next_line(0, &line)))
	{
		if (read <= 0)
			return (0);
		add_input_line(t_in, line);
		if (check_line_start_end(line) == 0)
			return (0);
		else if (check_line_start_end(line) == 2)
			continue ;
		else if (check_line_start_end(line) == 1)
		{
			if (read_ant_num(&line, i) == 0)
				return (0);
			else
				return (1);
		}
	}
	return (1);
}

int		read_start(t_anthill **t_str, t_input **t_in)
{
	char	*line;
	int		read;

	line = NULL;
	while ((read = get_next_line(0, &line)))
	{
		if (read <= 0)
			return (0);
		add_input_line(t_in, line);
		if (check_line_start_end(line) == 0)
			return (0);
		else if (check_line_start_end(line) == 1)
			break ;
		else if (check_line_start_end(line) == 2)
			continue ;
	}
	if (check_room(line) == 0)
		return (0);
	if (add_room(t_str, line, 's') == 0)
		return (0);
	return (1);
}

int		read_end(t_anthill **t_str, t_input **t_in)
{
	char	*line;
	int		read;

	line = NULL;
	while ((read = get_next_line(0, &line)))
	{
		if (read <= 0)
			return (0);
		add_input_line(t_in, line);
		if (check_line_start_end(line) == 0)
			return (0);
		else if (check_line_start_end(line) == 1)
			break ;
		else if (check_line_start_end(line) == 2)
			continue ;
	}
	if (check_room(line) == 0)
		return (0);
	if (add_room(t_str, line, 'f') == 0)
		return (0);
	return (1);
}

int		read_room(char *line, t_anthill **t_str)
{
	if (check_room(line) == 0)
		return (0);
	if (add_room(t_str, line, 'e') == 0)
		return (0);
	return (1);
}

int		read_conection(t_anthill **t_str, char *line)
{
	int		len;
	char	*first;
	char	*second;

	len = ft_roomlen(line);
	first = (char*)malloc(sizeof(char) * len + 1);
	first[len] = '\0';
	while (--len >= 0)
		first[len] = line[len];
	second = ft_strdup(ft_strchr(line, '-') + 1);
	if (check_connection(t_str, first, second) > 0)
	{
		write_connection(first, second, t_str);
		write_connection(second, first, t_str);
		free(second);
		free(first);
	}
	else if (check_connection(t_str, first, second) == 0)
	{
		free(second);
		free(first);
		return (0);
	}
	return (1);
}
