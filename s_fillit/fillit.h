/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:10:27 by bmoore            #+#    #+#             */
/*   Updated: 2019/04/21 14:26:19 by aaluko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <strings.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct		s_tetrimino
{
	char				let;
	int					avail;
	int					*num;
	int					pos;
	int					row;
	int					col;
	struct s_tetrimino	*next;
}					t_tetri;

char				**prty1_3(int c, char let);
char				**prty4_7(int c, char let);
char				**prty8_11(int c, char let);
char				**prty12_15(int c, char let);
char				**prty16_19(int c, char let);
int					chk_prty(int sum, int *a, int *ret, t_tetri *lst);
int					read_fill(int fd, t_tetri *lst);
t_tetri				*init_nodes(void);
char				**get_type(int c, char let);
t_tetri				*get_check(char **board, t_tetri *lst, int *num);
int					comp_ad(char **board, t_tetri *node, int *num);
int					cmp_cd(char **b, t_tetri *node, int *n);
int					cmp_d(char **b, t_tetri *node, int *n);
void				ext_fill(t_tetri *lst);
int					solve_tetri(t_tetri *lst, char **board, int *num, int i);
void				add_node(char **board, t_tetri *node, int *num);
void				free_lst(t_tetri *lst);

#endif
