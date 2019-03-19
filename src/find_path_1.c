/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:34:30 by pmartyny          #+#    #+#             */
/*   Updated: 2019/03/18 09:34:31 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		push_stack(t_stack **stack)
{
	t_conn		*tmp;
	t_stack		*tmp_stack;

	tmp_stack = (*stack);
	while (tmp_stack->next != NULL)
		tmp_stack = tmp_stack->next;
	tmp = (*stack)->room->conn;
	while (tmp != NULL)
	{
		if (tmp->room->pos == 'f')
		{
			tmp->room->prev = (*stack)->room;
			return (0);
		}
		if (tmp->room->visited == false && tmp->room->block == false)
			add_stack(&tmp, stack, &tmp_stack);
		tmp = tmp->next;
	}
	return (1);
}

void	add_stack(t_conn **tmp, t_stack **stack, t_stack **tmp_stack)
{
	t_stack		*new;

	new = (t_stack *)ft_memalloc(sizeof(t_stack));
	new->room = (*tmp)->room;
	(*tmp_stack)->next = new;
	(*tmp)->room->prev = (*stack)->room;
	(*tmp)->room->visited = true;
	(*tmp_stack) = (*tmp_stack)->next;
}

void	get_path(t_anthill **t_str, t_path **path)
{
	t_anthill	*finish;
	t_anthill	*tmp;
	int			i;

	i = 0;
	finish = find_finish(t_str);
	tmp = finish;
	while (tmp->prev != NULL)
	{
		i++;
		add_path(&tmp, path);
		tmp->prev->block = true;
		tmp = tmp->prev;
	}
	(*path)->length = i;
}

void	add_path(t_anthill **tmp, t_path **path)
{
	t_path		*new;

	new = (t_path*)ft_memalloc(sizeof(t_path));
	new->name = (*tmp)->name;
	new->pos = (*tmp)->pos;
	if ((*path) == NULL)
		(*path) = new;
	else
	{
		new->next = (*path);
		(*path) = new;
		(*path)->next->prev = new;
	}
}
