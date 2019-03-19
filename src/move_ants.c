/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:10:35 by pmartyny          #+#    #+#             */
/*   Updated: 2019/03/15 15:10:36 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	move_ants(t_path ***path)
{
	int		end;
	int		ant;
	int		i;

	end = 1;
	ant = 1;
	while (end)
	{
		i = 0;
		while ((*path)[i] != NULL)
		{
			if ((*path)[i]->ant == 0 && check_path(path, i) == 1)
			{
				(*path)[i]->ant = ant++;
				g_ant_number--;
				(*path)[i]->ant_count++;
			}
			i++;
		}
		end = move(path);
		ft_printf("\n");
		g_line_number++;
	}
}

void	move_all_ants(t_anthill **t_str)
{
	t_anthill	*finish;
	int			i;

	finish = find_finish(t_str);
	i = 1;
	while (g_ant_number > 0)
	{
		ft_printf("L%d-%s", i, finish->name);
		i++;
		g_ant_number--;
		if (g_ant_number > 0)
			ft_printf(" ");
	}
	ft_printf("\n");
}

int		move(t_path ***path)
{
	t_path	*tmp;
	int		i;
	int		res;

	i = 0;
	res = 0;
	while ((*path)[i])
	{
		tmp = (*path)[i];
		while (tmp && tmp->ant == 0)
			tmp = tmp->next;
		while (tmp && tmp->next && tmp->next->ant != 0)
			tmp = tmp->next;
		print_ant_moves(&tmp, &(*path)[i]);
		if ((*path)[i]->ant_count > 0)
			res++;
		if ((*path)[i + 1] && (*path)[i + 1]->ant_count > 0)
			ft_printf(" ");
		i++;
	}
	if (res > 0)
		return (1);
	else
		return (0);
}

void	print_ant_moves(t_path **tmp, t_path **path)
{
	while ((*tmp) && (*tmp)->ant != 0)
	{
		ft_printf("L%d-%s", (*tmp)->ant, (*tmp)->name);
		if ((*tmp)->pos == 'f')
		{
			(*path)->ant_count--;
			(*tmp)->ant = (*tmp)->prev->ant;
		}
		else
		{
			(*tmp)->next->ant = (*tmp)->ant;
			if ((*tmp)->prev)
				(*tmp)->ant = (*tmp)->prev->ant;
			else
				(*tmp)->ant = 0;
		}
		if ((*tmp)->prev && (*tmp)->prev->ant != 0)
			ft_printf(" ");
		else
			break ;
		(*tmp) = (*tmp)->prev;
	}
}

int		check_path(t_path ***path, int i)
{
	int		j;
	int		sum;

	j = 0;
	sum = 0;
	while (j < i)
	{
		sum += (*path)[i]->length - (*path)[j]->length;
		j++;
	}
	if (g_ant_number > sum)
		return (1);
	return (0);
}
