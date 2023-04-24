/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_expand_next_word.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:27:55 by jduval            #+#    #+#             */
/*   Updated: 2023/04/24 11:35:24 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/parsing.h"
#include "../../includes/utils.h"

TEST	test1(void)
{
	char	*str = "lol$lol\'mdr\'$mdr";
	ASSERT_EQ_FMT(3, next_expand_word(str, 0), "%d");
	PASS();
}

TEST	test2(void)
{
	char	*str = "lol$lol\'mdr\'$mdr";
	ASSERT_EQ_FMT(7, next_expand_word(str, 3 + 1), "%d");
	PASS();
}

TEST	test3(void)
{
	char	*str = "lol$lol\'mdr\'$mdr";
	ASSERT_EQ_FMT(12, next_expand_word(str, 7 + 1), "%d");
	PASS();
}

TEST	test4(void)
{
	char	*str = "lol$lol\'mdr\'$mdr";
	ASSERT_EQ_FMT(16, next_expand_word(str, 12 + 1), "%d");
	PASS();
}

SUITE (test_exp_nextword)
{
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
}
