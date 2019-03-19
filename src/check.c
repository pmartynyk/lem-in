/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:33:33 by pmartyny          #+#    #+#             */
/*   Updated: 2019/03/05 14:33:35 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		check_room(char *line)
{
	int		i;
	int		check;

	i = -1;
	check = 0;
	if (line[0] == ' ' || line[0] == 'L')
		return (0);
	while (line[++i] != ' ')
		if (line[i] == '-')
			return (0);
	while (line[++i] != ' ')
		if (ft_isdigit(line[i]) == 0)
			return (0);
		else
			check++;
	if (check == 0)
		return (0);
	check = 0;
	while (line[++i] != '\0')
		if (ft_isdigit(line[i]) == 0)
			return (0);
		else
			check++;
	return (check);
}

int		check_start_finish(t_anthill **t_str)
{
	int			start;
	int			finish;
	t_anthill	*temp;

	start = 0;
	finish = 0;
	temp = (*t_str);
	while (temp != NULL)
	{
		if (temp->pos == 's')
			start++;
		if (temp->pos == 'f')
			finish++;
		temp = temp->next;
	}
	if (start != 1 || finish != 1)
		return (0);
	return (1);
}

int		check_line_start_end(char *line)
{
	if (ft_strchr(line, '#'))
	{
		if (ft_strcmp(line, "##start") == 0 ||
			ft_strcmp(line, "##end") == 0)
			return (0);
		else if (line[0] == '#')
			return (2);
	}
	return (1);
}

int		check_connection(t_anthill **t_str, char *first, char *second)
{
	t_anthill	*tmp1;
	t_anthill	*tmp2;
	t_conn		*con_tmp;

	if (check_start_finish(t_str) == 0)
		return (0);
	if (ft_strcmp(first, second) == 0)
		return (0);
	tmp1 = find_room_by_name(t_str, first);
	tmp2 = find_room_by_name(t_str, second);
	if (tmp1 == NULL || tmp2 == NULL)
		return (-1);
	con_tmp = tmp1->conn;
	while (con_tmp != NULL)
	{
		if (ft_strcmp(con_tmp->room->name, second) == 0)
			return (0);
		con_tmp = con_tmp->next;
	}
	return (1);
}
