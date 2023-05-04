/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:55:57 by jduval            #+#    #+#             */
/*   Updated: 2023/04/27 16:20:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static char	**build_empty_path(void);
static char	**build_path(char *str);
static char	*refine_path(char *envp);
static int	find_path(char **envp);

char	**make_array_path(char **envp)
{
	char	**path;
	char	*str;
	int		index;

	index = find_path(envp);
	if (index == -1)
	{
		path = build_empty_path();
		if (path == NULL)
			return (NULL);
		return (path);
	}
	str = refine_path(envp[index]);
	if (str == NULL)
		return (NULL);
	path = build_path(str);
	free(str);
	if (path == NULL)
		return (NULL);
	return (path);
}

static int	find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static char	*refine_path(char *envp)
{
	char	*str;
	int		len;

	if (envp == NULL)
		return (NULL);
	len = ft_strlen(envp);
	str = ft_substr(envp, 5, len);
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	**build_path(char *str)
{
	char	**path;
	int		i;

	i = 0;
	path = ft_split(str, ':');
	if (path == NULL)
		return (NULL);
	while (path[i] != NULL)
	{
		path[i] = ft_strjoin_free(path[i], "/");
		if (path[i] == NULL)
		{
			if (i > 0)
				free_array2d(path);
			return (NULL);
		}
		i++;
	}
	return (path);
}

static char	**build_empty_path(void)
{
	char	**path;

	path = ft_calloc(sizeof(char *), 2);
	if (path == NULL)
		exit(0);
	return (path);
}
