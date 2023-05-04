/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split_endword.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <jduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:27:55 by jduval            #+#    #+#             */
/*   Updated: 2023/04/21 17:08:03 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../greatest.h"
#include "../../includes/utils.h"

TEST	test1(void)
{
	char	*str = "je suis ton";

	ASSERT_EQ_FMT(2, end_word(str, "\n\t "), "%d");
	PASS();
}

TEST	test2(void)
{
	char	*str = "je suis ton";

	ASSERT_EQ_FMT(4, end_word(&str[3], "\n\t "), "%d");
	PASS();
}

TEST	test3(void)
{
	char	*str = "je suis ton";

	ASSERT_EQ_FMT(3, end_word(&str[8], "\n\t "), "%d");
	PASS();
}

TEST	test4(void)
{
	ASSERT_EQ_FMT(0, end_word("", "\n\t "), "%d");
	PASS();
}

SUITE (test_split_endword)
{
	RUN_TEST(test1);
	RUN_TEST(test2);
	RUN_TEST(test3);
	RUN_TEST(test4);
}
