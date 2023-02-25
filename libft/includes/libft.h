/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:44:00 by kramjatt          #+#    #+#             */
/*   Updated: 2023/02/24 20:15:24 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

/*--------Libft_f-------*/
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);

char	*ft_strjoin(char *s1, char *s2);

int		ft_strrchr(const char *s, int c);
int		ft_strlen(const char *s);

/*--------GNL_f-------*/
char	*get_next_line(int fd);

#endif
