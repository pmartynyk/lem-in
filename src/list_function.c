/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:20:50 by pmartyny          #+#    #+#             */
/*   Updated: 2019/02/27 16:20:51 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		add_room(t_anthill **t_str, char *room, char pos)
{
	t_anthill	*new;
	t_anthill	*tmp;

	tmp = (*t_str);
	new = (t_anthill *)ft_memalloc(sizeof(t_anthill));
	room_name(room, &new, pos);
	if (tmp == NULL)
		(*t_str) = new;
	else
	{
		while (tmp->next != NULL)
		{
			if ((tmp->x == new->x && tmp->y == new->y) ||
				ft_strcmp(tmp->name, new->name) == 0)
				return (0);
			tmp = tmp->next;
		}
		if ((tmp->x == new->x && tmp->y == new->y) ||
			ft_strcmp(tmp->name, new->name) == 0)
			return (0);
		tmp->next = new;
	}
	return (1);
}

void	room_name(char *room, t_anthill **new, char pos)
{
	int		name_len;

	(*new)->x = ft_atoi(ft_strchr(room, ' '));
	(*new)->y = ft_atoi(ft_strrchr(room, ' '));
	name_len = room_name_len(room);
	(*new)->name = (char *)malloc(sizeof(char) * name_len + 1);
	(*new)->name[name_len] = '\0';
	while (--name_len >= 0)
		(*new)->name[name_len] = room[name_len];
	(*new)->pos = pos;
}

int		room_name_len(char *room)
{
	int	i;

	i = 0;
	while (room[i] != ' ' && room[i])
		i++;
	return (i);
}

void	add_input_line(t_input **t_in, char *line)
{
	t_input *new;
	t_input	*tmp;

	tmp = (*t_in);
	new = (t_input *)ft_memalloc(sizeof(t_input));
	new->line = line;
	if (tmp == NULL)
		(*t_in) = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	write_connection(char *str, char *in, t_anthill **t_str)
{
	t_anthill	*tmp;
	t_conn		*new;

	new = (t_conn *)ft_memalloc(sizeof(t_conn));
	tmp = (*t_str);
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, str) == 0)
		{
			new->room = find_room_by_name(t_str, in);
			if (tmp->conn == NULL)
				tmp->conn = new;
			else
			{
				new->next = tmp->conn;
				tmp->conn = new;
			}
			return ;
		}
		tmp = tmp->next;
	}
}
