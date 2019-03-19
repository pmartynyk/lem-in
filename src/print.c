/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:07:06 by pmartyny          #+#    #+#             */
/*   Updated: 2019/03/01 15:07:07 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	print_input(t_input **t_in)
{
	t_input	*tmp;
	int		i;

	i = 0;
	tmp = (*t_in);
	while (tmp->next != NULL)
	{
		ft_printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}

void	print_str(t_anthill **t_str)
{
	t_anthill	*tmp;
	t_conn		*tmp1;
	int			i;

	i = 0;
	tmp = (*t_str);
	while (tmp != NULL)
	{
		ft_printf("name : %s\n", tmp->name);
		ft_printf("%d | %d\n", tmp->x, tmp->y);
		ft_printf("type : %c\n", tmp->pos);
		tmp1 = tmp->conn;
		while (tmp1 != NULL)
		{
			ft_printf("%s ", tmp1->room->name);
			tmp1 = tmp1->next;
		}
		ft_printf("\n");
		ft_printf("------------\n");
		tmp = tmp->next;
	}
}

void	write_path(t_path ***path)
{
	int			i;
	t_path		*tmp;

	i = 0;
	while ((*path)[i] != NULL)
	{
		tmp = (*path)[i];
		while (tmp != NULL)
		{
			ft_printf("%s--", tmp->name);
			tmp = tmp->next;
		}
		i++;
		ft_printf("\n");
	}
}

void	write_usage(void)
{
	ft_printf("usage: ./lem_in [flags | -i -r] < [file]\n");
	ft_printf("\t\t -i - write only input\n");
	ft_printf("\t\t -r - write number of lines\n");
}

int		lines_need(t_input **t_in)
{
	t_input	*tmp;
	int		res;

	res = 0;
	tmp = (*t_in);
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->line, "#Here is the number of lines required:", 30)
			== 0)
			res = ft_atoi(ft_strchr(tmp->line, ':') + 1);
		tmp = tmp->next;
	}
	return (res);
}
