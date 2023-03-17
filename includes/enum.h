/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:25 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/17 22:14:17 by jduval           ###   ########.fr       */
/*   Updated: 2023/03/15 11:33:40 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

/*-------Libraries------*/

# include "../src/libft/include/libft.h"

/*-------Headers------*/

/*--------Structs-------*/

/*--------Enum-------*/

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

/*--------Structs-------*/

typedef struct s_builts
{
	char	*str;

}	t_builts;

typedef struct s_mini
{	
	int			exit;
	char		*current_dir;
	char		*old_dir;
	char		**envp_cpy;
	char		**cmd;
	t_builts	*b_ptr;

}	t_mini;

typedef	struct s_red
{
	char	*name;
	t_way	way;
	int		fd;
}	t_red;

typedef struct s_cmd
{
	char	**cmd;
	t_bool	valid;
	int		index;
	t_mini	*utils;
}	t_cmd;

typedef union u_type
{
	t_red			rdirct;
	t_cmd			cmds;
	union u_type	*ptr;
}	t_type;

#endif
