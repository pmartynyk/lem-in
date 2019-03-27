/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 07:03:13 by pmartyny          #+#    #+#             */
/*   Updated: 2019/03/06 07:03:15 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			ft_roomlen(char *line)
{
	int i;

	i = 0;
	while (line[i] != '-')
		i++;
	return (i);
}

t_anthill	*find_start(t_anthill **t_str)
{
	t_anthill	*tmp;

	tmp = (*t_str);
	while (tmp != NULL)
	{
		if (tmp->pos == 's')
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

t_anthill	*find_finish(t_anthill **t_str)
{
	t_anthill	*tmp;

	tmp = (*t_str);
	while (tmp != NULL)
	{
		if (tmp->pos == 'f')
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

int			count_output_rooms(t_anthill **t_str)
{
	t_conn		*tmp;
	t_anthill	*start;
	int			res;

	start = find_start(t_str);
	tmp = start->conn;
	res = 0;
	while (tmp != NULL)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

int			path_count(t_path ***path)
{
	int res;

	res = 0;
	while ((*path)[res] != NULL)
		res++;
	return (res);
}
