/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:30 by kramjatt          #+#    #+#             */
/*   Updated: 2023/03/16 17:36:01 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

/*-------Libraries------*/
# include <limits.h>
# include <stdio.h>
/*-------Headers------*/
# include "clear.h"
# include "enum.h"
# include "../src/libft/include/libft.h"

/*-----Built_IN_f-----*/
void	ft_cd(t_mini *mini);
void	ft_echo(t_mini *mini);
void	ft_env(t_mini *mini);
void	ft_exit(t_mini *mini);
void	ft_export(t_mini *mini);
void	ft_pwd(t_mini *mini);
void	ft_unset(t_mini *mini);
void	is_built(t_mini *mini);

/*-----Init_f-----*/
void	init_builts(t_builts *builts);

#endif
