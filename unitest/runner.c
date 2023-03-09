/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:56:09 by jduval            #+#    #+#             */
/*   Updated: 2023/03/09 13:58:10 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

SUITE (nameofsuite)

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();	/*	command line initialization. */

	/* Test can also be gathered into test suites. */
	RUN_SUITE(name of suite);

	GREATEST_MAIN_END();	/* display result */
}
