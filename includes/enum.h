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
