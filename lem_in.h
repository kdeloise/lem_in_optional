/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdeloise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:42:37 by kdeloise          #+#    #+#             */
/*   Updated: 2020/02/25 20:42:42 by kdeloise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

#include "libft/libft.h"
typedef struct			s_room t_room;
typedef struct			s_link t_link;

typedef struct			s_link_list
{
	t_link				*data;
	struct s_link_list	*next;
}						t_link_list;

typedef struct			s_llist
{
	t_room			*data;
	struct s_llist	*next;
}						t_llist;

struct				s_room
{
	char 			*name;				//имя комнаты
	int				x;					//координаты
	int				y;					//команты
	t_link_list 	*links;				// neighbors: list of pointers to Link Кол-во ребер
	int 			distance;			// mmarti
	struct s_room	*parent;			// for Dijkstra's algorithm (see Appendix in Bhandari's article) mmarti
	struct s_room	*pred;				//	mmarti
	struct s_room	*succ;				// pointers to adjacent rooms along the path mmarti
};

struct				s_link
{
	int 			weight;				// 1
	t_room 			*dst;				// куда указывает ребро на какую комнату
};

typedef struct			s_graph
{
	t_llist			*rooms;                // list of pointers to Room
	t_room			*start;
	t_room			*end;
}						t_graph;

typedef struct			s_flags
{
	t_room			**array_of_rooms_ptr;
	int				count_of_ants;
    int             count_of_room;
    int				count_of_path;
    int				count_of_edges;
	int				ant;
	int				con;
	int				start;
	int				end;
}						t_flags;

typedef	struct			s_path
{
	t_room				*room;
	struct s_path		*next;
}						t_path;

void				ft_exit(const char *const str);

void				ft_quick_sort_coor(t_room **array, int start, int end);
void				ft_quick_sort(t_room **array, int start, int end);
void				create_array_of_rooms_ptr(t_flags *flag, t_graph *graph);


void				create_links(t_graph *graph, char *name_coor);

void				create_links_binary(t_graph *graph, char *name_coor, t_flags *flags);

void				check_double_name(t_room **array_of_rooms_ptr, int count);
void				check_double_coor(t_room **array_of_rooms_ptr, int count);
void				create_rooms(t_graph *graph, char *name_coor);
void				create_start_room(t_graph *graph, char *name_coor);
void				create_end_room(t_graph *graph, char *name_coor);

char				*create_validation_buff(void);
t_graph				*validation(char	*buff);

// void				suurbale(t_graph *graph)
#endif
