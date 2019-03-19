/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 10:40:54 by pmartyny          #+#    #+#             */
/*   Updated: 2019/02/27 10:40:56 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft_printf/includes/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef	struct			s_path {
	struct s_path		*prev;
	char				*name;
	char				pos;
	int					ant;
	int					ant_count;
	int					length;
	struct s_path		*next;
}						t_path;

typedef	struct			s_stack {
	struct s_anthill	*room;
	struct s_stack		*next;
}						t_stack;

typedef	struct			s_input {
	char				*line;
	struct s_input		*next;
}						t_input;

typedef	struct			s_conn{
	struct s_anthill	*room;
	struct s_conn		*next;
}						t_conn;

typedef struct			s_anthill{

	struct s_anthill	*prev;
	bool				visited;
	bool				block;
	char				*name;
	int					x;
	int					y;
	char				pos;
	struct s_conn		*conn;
	struct s_anthill	*next;
}						t_anthill;

int						g_ant_number;
int						g_line_number;
/*
**lem_in.c
*/
int						read_input(t_anthill **t_str, t_input **t_in,
	t_path ***path, int flag);
int						convert_line(t_anthill **t_str, t_input **t_in,
	char *line);
int						convert_line_2(t_anthill **t_str, char *line);
void					parse_flag(t_anthill **t_str, t_input **t_in,
	t_path ***path, int flag);

/*
**read.c
*/
int						read_ant_number(t_input **t_in);
int						read_start(t_anthill **t_str, t_input **t_in);
int						read_end(t_anthill **t_str, t_input **t_in);
int						read_room(char *line, t_anthill **t_str);
int						read_conection(t_anthill **t_str, char *line);
/*
**list_function.c
*/
int						add_room(t_anthill **t_str, char *room, char pos);
int						room_name_len(char *room);
void					add_input_line(t_input **t_in, char *line);
void					room_name(char *room, t_anthill **new,
	char pos);
void					write_connection(char *str, char *in,
	t_anthill **t_str);
/*
**list_function_2.c
*/
t_anthill				*find_room_by_name(t_anthill **t_str, char *room);
int						read_ant_num(char **line, int i);

/*
**print.c
*/
void					print_input(t_input **t_in);
void					print_str(t_anthill **t_str);
void					write_path(t_path ***path);
void					write_usage(void);
int						lines_need(t_input **t_in);
/*
**check.c
*/
int						check_room(char *line);
int						check_start_finish(t_anthill **t_str);
int						check_line_start_end(char *line);
int						check_connection(t_anthill **t_str, char *first,
	char *second);
/*
**additional.c
*/
int						ft_roomlen(char *line);
int						count_output_rooms(t_anthill **t_str);
t_anthill				*find_start(t_anthill **t_str);
t_anthill				*find_finish(t_anthill **t_str);
int						path_count(t_path ***path);

/*
**find_path.c
*/
int						find_path(t_anthill **t_str, t_path ***path);
int						algorythm(t_anthill **t_str, t_path **path);
int						push_stack_start(t_anthill **t_str,
	t_stack **stack);
void					add_stack_start(t_anthill **start, t_conn **tmp,
	t_stack **stack);
void					unvisited(t_anthill **t_str);
/*
**find_path_1.c
*/
int						push_stack(t_stack **stack);
void					add_stack(t_conn **tmp, t_stack **stack,
	t_stack **tmp_stack);
void					get_path(t_anthill **t_str, t_path **path);
void					add_path(t_anthill **tmp, t_path **path);
/*
**move_ants.c
*/
void					move_ants(t_path ***path);
void					move_all_ants(t_anthill **t_str);
int						move(t_path ***path);
int						check_path(t_path ***path, int i);
void					print_ant_moves(t_path **tmp, t_path **path);
#endif
