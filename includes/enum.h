/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:25 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/13 17:55:26 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

/*-------Libraries------*/

/*-------Headers------*/

/*--------Structs-------*/

typedef struct s_builts
{
	char	*str;

}	t_builts;

typedef struct s_mini
{	
	char		**cmd;
	char		**envp_cpy;
	int			exit;
	t_builts	*b_ptr;

}	t_mini;

#endif
