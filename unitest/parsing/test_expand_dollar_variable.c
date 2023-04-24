/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_dollar_variable.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:27:55 by jduval            #+#    #+#             */
/*   Updated: 2023/04/24 11:16:45 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/parsing.h"
#include "../../includes/utils.h"

TEST	test1(void)
{
	char	*str = "lol$lol\'mdr\'$mdr";
	ASSERT_EQ_FMT(7, dollar_end(str, 3 + 1), "%d");
	PASS();
}

TEST	test2(void)
{
	char	*str = "lol$lol\'mdr\'$mdr";
	ASSERT_EQ_FMT(16, dollar_end(str, 12 + 1), "%d");
	PASS();
}

SUITE (test_exp_dollarvariable)
{
	RUN_TEST(test1);
	RUN_TEST(test2);
}
