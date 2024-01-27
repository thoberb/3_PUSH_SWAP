/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:23:23 by bberthod          #+#    #+#             */
/*   Updated: 2023/04/04 12:23:00 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_pile
{
	int				nbr;
	int				index;
	struct s_pile	*prev;
	struct s_pile	*next;
}	t_pile;

typedef struct s_infos
{
	t_pile	*a;
	t_pile	*b;
	int		*tab;
	int		size;
	int		size_a;
	int		size_b;
}	t_infos;

// init.c
t_infos		*init(int argc, char **argv);
t_pile		*init_data(char **argv, int len, int *tab);
int			*create_tab(char **argv, int len);
int			sort_tab(int *tab, int len);

// exec.c
int			ft_exec(t_infos *piles);
int			ft_exec_cmd(t_infos *piles, char *mouv);

// utils.c
int			ft_isnbr(const char *str);
int			ft_atoi(const char *nptr);
int			ft_strlen(char *s);
int			ft_cmp(char *mouv, char *cmd);

// utils_lst.c
t_pile		*ft_lstnew(int nombre, int *tab, int len);
t_pile		*ft_lstadd_back(t_pile *lst, int nombre, int *tab, int len);
t_pile		*ft_lstlast(t_pile *lst);
int			find_range_up(t_pile *lst);

// test.c
int			correct(t_pile *lst);
int			parse(char **argv, int len);
int			ft_check_piles(t_infos *piles);

// free.c
void		ft_free_piles(t_infos *piles);
void		ft_free_element(t_pile *lst);

// mouvs_swap.c
int			ft_lstsize(t_pile *lst);
int			sa(t_infos *piles);
int			sb(t_infos *piles);
int			ss(t_infos *piles);

// mouvs_push.c
int			pa(t_infos *piles);
int			pb(t_infos *piles);

// mouvs_rotate.c
int			ra(t_infos *piles);
int			rb(t_infos *piles);
int			rr(t_infos *piles);

// mouvs_rev_rot.c
int			rra(t_infos *piles);
int			rrb(t_infos *piles);
int			rrr(t_infos *piles);

// get_next_line.c
char		*get_next_line(int fd);
char		*ft_next(char *buffer);
char		*ft_line(char *buffer);
char		*ft_read(int fd, char *buffer);
char		*ft_tmp(char *tmp, char *buffer);

// get_next_line_utils.c
int			ft_strchr(char *str, char c);
char		*ft_strjoin(char *s1, char *s2);

#endif
