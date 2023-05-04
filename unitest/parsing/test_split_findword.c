/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split_findword.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:27:55 by jduval            #+#    #+#             */
/*   Updated: 2023/04/21 17:05:44 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"

TEST	test1(void)
{
	ASSERT_EQ_FMT(0, find_word("je suis ton pere", "\n\t "), "%d");
	PASS();
}

TEST	test2(void)
{
	ASSERT_EQ_FMT(0, find_word("je", "\n\t "), "%d");
	PASS();
}

TEST	test3(void)
{
	ASSERT_EQ_FMT(0, find_word("je suis ton", "\n\t "), "%d");
	PASS();
}

TEST	test4(void)
{
	ASSERT_EQ_FMT(6, find_word("   \n\t j \n\t   suis   ton     ", "\n\t "), "%d");
	PASS();
}

TEST	test5(void)
{
	ASSERT_EQ_FMT(0, find_word("", "\n\t "), "%d");
	PASS();
}

TEST	test6(void)
{
	ASSERT_EQ_FMT(7, find_word("  \n\t   ", "\n\t "), "%d");
	PASS();
}

SUITE (test_split_findword)
{
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
	RUN_TEST(test5);
	RUN_TEST(test6);
}
