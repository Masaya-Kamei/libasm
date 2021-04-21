/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:52:39 by mkamei            #+#    #+#             */
/*   Updated: 2021/04/21 12:28:31 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_BONUS_H
# define LIBASM_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
ssize_t				ft_write(int d, const void *buf, size_t nbytes);
ssize_t				ft_read(int d, void *buf, size_t nbytes);
char				*ft_strdup(const char *str);
int					ft_atoi_base(char *str, char *base);
void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);
void				ft_list_sort(t_list **begin_list, int (*cmp)());
t_list				*ft_list_remove_if(t_list **begin_list, void *data_ref,
									int (*cmp)(), void (*free_fct)(void *));

#endif
