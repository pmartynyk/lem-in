/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 04:52:48 by pmartyny          #+#    #+#             */
/*   Updated: 2019/03/06 04:52:50 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		find_path(t_anthill **t_str, t_path ***path)
{
	int		count;
	int		i;

	i = 0;
	count = count_output_rooms(t_str);
	(*path) = (t_path**)ft_memalloc(sizeof(t_path*) * (count + 1));
	while (i < (count + 1))
	{
		if (algorythm(t_str, &(*path)[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		algorythm(t_anthill **t_str, t_path **path)
{
	t_stack		*stack;
	t_stack		*del_stack;

	if (push_stack_start(t_str, &stack) == 0)
		return (0);
	while (stack != NULL)
	{
		del_stack = stack;
		if (push_stack(&stack) == 0)
		{
			get_path(t_str, path);
			while (stack != NULL)
			{
				del_stack = stack;
				stack = stack->next;
				free(del_stack);
			}
			unvisited(t_str);
			return (1);
		}
		stack = stack->next;
		free(del_stack);
	}
	return (1);
}

int		push_stack_start(t_anthill **t_str, t_stack **stack)
{
	t_conn		*tmp;
	t_anthill	*start;

	start = find_start(t_str);
	tmp = start->conn;
	start->visited = true;
	(*stack) = NULL;
	while (tmp != NULL)
	{
		if (tmp->room->pos == 'f')
		{
			move_all_ants(t_str);
			return (0);
		}
		if (tmp->room->visited == false && tmp->room->block == false)
			add_stack_start(&start, &tmp, stack);
		tmp = tmp->next;
	}
	return (1);
}

void	add_stack_start(t_anthill **start, t_conn **tmp, t_stack **stack)
{
	t_stack		*count;
	t_stack		*new;

	new = (t_stack *)ft_memalloc(sizeof(t_stack));
	new->room = (*tmp)->room;
	if ((*stack) != NULL)
	{
		count = (*stack);
		while (count->next != NULL)
			count = count->next;
		count->next = new;
	}
	else
		(*stack) = new;
	(*tmp)->room->prev = (*start);
	(*tmp)->room->visited = true;
}

void	unvisited(t_anthill **t_str)
{
	t_anthill	*tmp;

	tmp = (*t_str);
	while (tmp != NULL)
	{
		if (tmp->block == false)
			tmp->visited = false;
		tmp = tmp->next;
	}
}
