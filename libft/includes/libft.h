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

void	ft_strcpy(char *dst, const char *src);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr_fd(int fd, char *s);

char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	**cpy_array2d(char **array2d);

int		count_args_2d(char **array2d);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, int size);
int		ft_strlen(const char *s);
int		ft_strrchr(const char *s, int c);

/*--------GNL_f-------*/
char	*get_next_line(int fd);

/*--------Free_f-------*/
void	free_array2d(char **arr);

#endif
