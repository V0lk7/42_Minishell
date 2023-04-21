/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split_comparedelim.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:27:55 by jduval            #+#    #+#             */
/*   Updated: 2023/04/21 16:37:08 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"

TEST	test1(void)
{
	ASSERT_EQ_FMT(TRUE, compare_delim('\t', "\n\t "), "%d");
	PASS();
}

TEST	test2(void)
{
	ASSERT_EQ_FMT(FALSE, compare_delim('j', "\n\t "), "%d");
	PASS();
}

TEST	test3(void)
{
	ASSERT_EQ_FMT(TRUE, compare_delim(' ', "\n\t "), "%d");
	PASS();
}

TEST	test4(void)
{
	ASSERT_EQ_FMT(TRUE, compare_delim('\n', "\n\t \0"), "%d");
	PASS();
}

SUITE (test_split_comparedelim)
{
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
}
