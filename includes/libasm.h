/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:58:05 by mkamei            #+#    #+#             */
/*   Updated: 2021/04/14 20:04:33 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>

size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int d, const void *buf, size_t nbytes);
ssize_t			ft_read(int d, void *buf, size_t nbytes);
char			*ft_strdup(const char *str);

#endif
