/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:33:06 by kramjatt          #+#    #+#             */
/*   Updated: 2023/02/24 19:54:29 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_extract(char *to_extract)
{
	int		i;
	int		j;
	char	*extracted;

	i = 0;
	j = 0;
	while (to_extract[i] != '\n')
		i++;
	extracted = ft_calloc(((ft_strlen(to_extract) + 1) - i), sizeof(char));
	i++;
	if (extracted == NULL)
		return (NULL);
	while (to_extract[i] != '\0')
	{
		extracted[j] = to_extract[i];
		j++;
		i++;
	}
	if (ft_strlen(extracted) == 0)
	{
		free(extracted);
		extracted = NULL;
	}
	return (extracted);
}

static char	*ft_truncate(char *to_truncate)
{
	int		i;

	i = 0;
	while (to_truncate[i] != '\0')
	{
		if (to_truncate[i] == '\n')
			to_truncate[i + 1] = '\0';
		i++;
	}
	return (to_truncate);
}

static int	ft_check_ret(int fd, char *buf, char *save, char *line)
{
	int	ret;

	ret = 0;
	ret = read (fd, buf, BUFFER_SIZE);
	if (ret == -1)
	{
		free(buf);
		free(save);
		free(line);
		return (-3);
	}
	buf[ret] = '\0';
	if (ret == 0)
	{
		free(buf);
		if (line != NULL && line[0] != '\0')
			return (-2);
		else
		{
			free(line);
			return (-3);
		}
	}
	return (ret);
}

static int	ft_read(int fd, char *save, char **line)
{
	int			count;
	char		*buf;

	count = 0;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf == NULL)
		return (-3);
	while (ft_strrchr(*line, '\n') == -1)
	{
		if (save == NULL)
		{
			count = ft_check_ret(fd, buf, save, *line);
			if (count == -2 || count == -3)
				return (count);
		}
		else
		{
			*line = ft_strjoin(*line, save);
			if (!(ft_strrchr(save, '\n') > 0))
				save = NULL;
		}
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	return (count);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*final_value;
	char		*line;
	int			to_return;

	if (BUFFER_SIZE <= 0 || (fd < 0 || fd > 1024))
		return (NULL);
	line = NULL;
	final_value = NULL;
	to_return = ft_read(fd, save, &line);
	if (to_return == -2)
	{
		free(save);
		save = NULL;
		return (line);
	}
	else if (to_return == -3)
		return (NULL);
	if (ft_strrchr(line, '\n') != -1)
	{
		free(save);
		save = ft_extract(line);
		final_value = ft_truncate(line);
	}
	return (final_value);
}
