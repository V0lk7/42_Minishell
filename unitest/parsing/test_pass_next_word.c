/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pass_next_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:58:12 by jduval            #+#    #+#             */
/*   Updated: 2023/03/22 18:08:58 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"

TEST	test1(void)
{
	ASSERT_EQ_FMT(6, pass_next_word("je <ton pere", 3), "%d");
	PASS();
}

TEST	test2(void)
{
	ASSERT_EQ_FMT(11, pass_next_word("je ton <pere", 7), "%d");
	PASS();
}

TEST	test3(void)
{
	ASSERT_EQ_FMT(7, pass_next_word("je <<ton pere", 3), "%d");
	PASS();
}

TEST	test4(void)
{
	ASSERT_EQ_FMT(7, pass_next_word("je <<ton", 3), "%d");
	PASS();
}

SUITE (test_pass_next_word)
{
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
}
