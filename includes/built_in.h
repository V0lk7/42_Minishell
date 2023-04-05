/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:55:30 by kramjatt          #+#    #+#             */
/*   Updated: 2023/04/05 09:57:17 by jduval           ###   ########.fr       */
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
void	ft_cd(t_cmd *cmd);
void	ft_echo(t_cmd *cmd);
void	ft_env(t_cmd *cmd);
void	ft_exit(t_cmd *cmd, t_data *lst, t_mini *mini);
void	ft_export(t_cmd *cmd);
void	ft_pwd(t_cmd *cmd);
void	ft_unset(t_cmd *cmd);

//void	is_built(t_mini *mini);
void	is_built(t_cmd *cmd);

/*-----Utils_f-----*/
void	crush_export(t_mini *mini, char *exported);
void	print_export(char **array);
int		compare(char **array, char *str);
int		search_c(char *str, char c);
char	**sort_export(t_mini *mini);
int		verif_export(char *cmd);

/*-----Init_f-----*/
//void	init_builts(t_builts *builts);

#endif
