/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:21:25 by pmartyny          #+#    #+#             */
/*   Updated: 2019/03/07 13:21:28 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_anthill	*find_room_by_name(t_anthill **t_str, char *room)
{
	t_anthill	*tmp;

	tmp = (*t_str);
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, room) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

int			read_ant_num(char **line, int i)
{
	while ((*line)[++i])
		if (!ft_isdigit((*line)[i]))
			return (0);
	g_ant_number = ft_atoi((*line));
	if (g_ant_number > 0 && g_ant_number <= INT_MAX)
		return (1);
	else
		return (0);
}
