/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:25 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/02 14:46:34 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

/*--------Enum-------*/

extern int		g_status;

typedef enum e_spe
{
	NONE,
	REDIRECTION,
	PIPE
}	t_spe;

typedef enum e_way
{
	IN,
	OUT,
	HDOC,
	APPEND
}	t_way;

typedef enum e_class
{
	COMMAND,
	REDIRECT
}	t_class;

/*--------Structs-------*/

typedef struct s_mini
{	
	char		*current_dir;
	char		*old_dir;
	char		**envp_cpy;
	char		**path;
}	t_mini;

typedef struct s_expand
{
	char			**array;
	char			*word;
	int				id;
	struct s_expand	*next;
}	t_expand;

typedef struct s_hdoc
{
	char			*line;
	int				last;
	struct s_hdoc	*next;
}	t_hdoc;

typedef struct s_red
{
	char	**file;
	char	*save;
	t_way	way;
	t_hdoc	*input;
	int		expand;
	int		r_fd;
	int		w_fd;
}	t_red;

typedef struct s_cmd
{
	int			id;
	char		**cmd;
	int			valid;
	t_mini		*mini;
}	t_cmd;

typedef union u_type
{
	t_red			rdict;
	t_cmd			cmd;
}	t_type;

typedef struct s_data
{
	t_class			name;
	t_type			data;
	int				index;
	struct s_data	*next;
}	t_data;

typedef struct s_fd
{
	int	fds[2];
	int	write;
	int	read;
	int	std_in;
	int	std_out;
}	t_fd;

typedef void	t_builts(t_cmd *cmd);

#endif
